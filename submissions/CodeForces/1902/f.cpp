#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

template<size_t Dim> struct GaussianElimination {
  using T = conditional_t<Dim <= 32, uint32_t, uint64_t>;
  vector<T> basis;

  void insert(T x) {
    for (const auto &b : basis)
      x = min(x, x ^ b);
    if (x) basis.push_back(x);
  }

  void merge(const GaussianElimination &other) {
    for (int i = 0; basis.size() < Dim and i < other.size(); i++)
      insert(other.basis[i]);
  }

  void normalize() {
    sort(all(basis));
    for (int i = size() - 1; ~i; --i) {
      for (int j = i - 1; ~j; --j) {
        if (basis[i] & (1ll << (63 - __builtin_clzll(basis[j]))))
          basis[i] ^= basis[j];
      }
    }
  }

  bool check(T x) const {
    for (const auto &b : basis)
      x = min(x, x ^ b);
    return !x;
  }

  auto operator[](T k) const { return at(k); }
  int size() const { return (int) basis.size(); }

  // Need to call normalize() first
  T at(T k) const {
    T ans = 0;
    for (int i = 0; i <= size(); i++) {
      if (k & 1) ans ^= basis[i];
      k >>= 1;
    }
    return ans;
  }

  T max() const {
    return at((1ll << size()) - 1);
  }
};

struct HeavyLightDecomposition {
  int V;
  int id;
  int nb_heavy_path;
  std::vector<std::vector<int>> e;
  std::vector<int> par;         // par[i] = parent of vertex i (Default: -1)
  std::vector<int> depth;       // depth[i] = distance between root and vertex i
  std::vector<int> subtree_sz;  // subtree_sz[i] = size of subtree whose root is i
  std::vector<int> heavy_child; // heavy_child[i] = child of vertex i on heavy path (Default: -1)
  std::vector<int> tree_id;     // tree_id[i] = id of tree vertex i belongs to
  std::vector<int> aligned_id, aligned_id_inv;    // aligned_id[i] =  aligned id for vertex i (consecutive on heavy edges)
  std::vector<int> head; // head[i] = id of vertex on heavy path of vertex i, nearest to root
  std::vector<int> head_ids;      // consist of head vertex id's
  std::vector<int> heavy_path_id; // heavy_path_id[i] = heavy_path_id for vertex [i]


  HeavyLightDecomposition(const std::vector<std::vector<int>> &g, vector<int> roots = {0}) : HeavyLightDecomposition((int)g.size()) {
    this->e = g;
    build(roots);
  }
  HeavyLightDecomposition(int sz = 0)
      : V(sz), id(0), nb_heavy_path(0), e(sz), par(sz), depth(sz), subtree_sz(sz), heavy_child(sz),
        tree_id(sz, -1), aligned_id(sz), aligned_id_inv(sz), head(sz), heavy_path_id(sz, -1) {}

  void add_edge(int u, int v) {
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }

  void _build_dfs(int root) {
    std::stack<std::pair<int, int>> st;
    par[root] = -1;
    depth[root] = 0;
    st.emplace(root, 0);
    while (!st.empty()) {
      int now = st.top().first;
      int &i = st.top().second;
      if (i < (int)e[now].size()) {
        int nxt = e[now][i++];
        if (nxt == par[now]) continue;
        par[nxt] = now;
        depth[nxt] = depth[now] + 1;
        st.emplace(nxt, 0);
      } else {
        st.pop();
        int max_sub_sz = 0;
        subtree_sz[now] = 1;
        heavy_child[now] = -1;
        for (auto nxt : e[now]) {
          if (nxt == par[now]) continue;
          subtree_sz[now] += subtree_sz[nxt];
          if (max_sub_sz < subtree_sz[nxt])
            max_sub_sz = subtree_sz[nxt], heavy_child[now] = nxt;
        }
      }
    }
  }

  void _build_bfs(int root, int tree_id_now) {
    std::queue<int> q({root});
    while (!q.empty()) {
      int h = q.front();
      q.pop();
      head_ids.emplace_back(h);
      for (int now = h; now != -1; now = heavy_child[now]) {
        tree_id[now] = tree_id_now;
        aligned_id[now] = id++;
        aligned_id_inv[aligned_id[now]] = now;
        heavy_path_id[now] = nb_heavy_path;
        head[now] = h;
        for (int nxt : e[now])
          if (nxt != par[now] and nxt != heavy_child[now]) q.push(nxt);
      }
      nb_heavy_path++;
    }
  }

  void build(std::vector<int> roots = {0}) {
      int tree_id_now = 0;
      for (auto r : roots) _build_dfs(r), _build_bfs(r, tree_id_now++);
  }

  template <class T> std::vector<T> segtree_rearrange(const std::vector<T> &data) const {
    assert(int(data.size()) == V);
    std::vector<T> ret;
    ret.reserve(V);
    for (int i = 0; i < V; i++) ret.emplace_back(data[aligned_id_inv[i]]);
    return ret;
  }

  // query for vertices on path [u, v] (INCLUSIVE)
  void for_each_vertex(int u, int v, const auto &f) const {
    static_assert(std::is_invocable_r_v<void, decltype(f), int, int>);
    while (true) {
      if (aligned_id[u] > aligned_id[v]) std::swap(u, v);
      f(std::max(aligned_id[head[v]], aligned_id[u]), aligned_id[v]);
      if (head[u] == head[v]) break;
      v = par[head[v]];
    }
  }

  void for_each_vertex_noncommutative( int from, int to, const auto &fup, const auto &fdown) const {
    static_assert(std::is_invocable_r_v<void, decltype(fup), int, int>);
    static_assert(std::is_invocable_r_v<void, decltype(fdown), int, int>);
    int u = from, v = to;
    const int lca = lowest_common_ancestor(u, v), dlca = depth[lca];
    while (u >= 0 and depth[u] > dlca) {
      const int p = (depth[head[u]] > dlca ? head[u] : lca);
      fup(aligned_id[p] + (p == lca), aligned_id[u]), u = par[p];
    }
    static std::vector<std::pair<int, int>> lrs;
    int sz = 0;
    while (v >= 0 and depth[v] >= dlca) {
      const int p = (depth[head[v]] >= dlca ? head[v] : lca);
      if (int(lrs.size()) == sz) lrs.emplace_back(0, 0);
      lrs.at(sz++) = {p, v}, v = par.at(p);
    }
    while (sz--) fdown(aligned_id[lrs.at(sz).first], aligned_id[lrs.at(sz).second]);
  }

  // query for edges on path [u, v]
  void for_each_edge(int u, int v, const auto &f) const {
    static_assert(std::is_invocable_r_v<void, decltype(f), int, int>);
    while (true) {
      if (aligned_id[u] > aligned_id[v]) std::swap(u, v);
      if (head[u] != head[v]) {
        f(aligned_id[head[v]], aligned_id[v]);
        v = par[head[v]];
      } else {
        if (u != v) f(aligned_id[u] + 1, aligned_id[v]);
        break;
      }
    }
  }

  // lowest_common_ancestor: O(log V)
  int lowest_common_ancestor(int u, int v) const {
    assert(tree_id[u] == tree_id[v] and tree_id[u] >= 0);
    while (true) {
      if (aligned_id[u] > aligned_id[v]) std::swap(u, v);
      if (head[u] == head[v]) return u;
      v = par[head[v]];
    }
  }

  int distance(int u, int v) const {
    assert(tree_id[u] == tree_id[v] and tree_id[u] >= 0);
    return depth[u] + depth[v] - 2 * depth[lowest_common_ancestor(u, v)];
  }

  // Level ancestor, O(log V)
  // if k-th parent is out of range, return -1
  int kth_parent(int v, int k) const {
    if (k < 0) return -1;
    while (v >= 0) {
      int h = head.at(v), len = depth.at(v) - depth.at(h);
      if (k <= len) return aligned_id_inv.at(aligned_id.at(v) - k);
      k -= len + 1, v = par.at(h);
    }
    return -1;
  }

  // Jump on tree, O(log V)
  int s_to_t_by_k_steps(int s, int t, int k) const {
    if (k < 0) return -1;
    if (k == 0) return s;
    int lca = lowest_common_ancestor(s, t);
    if (k <= depth.at(s) - depth.at(lca)) return kth_parent(s, k);
    return kth_parent(t, depth.at(s) + depth.at(t) - depth.at(lca) * 2 - k);
  }
};

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T> struct DisjointSparseTable
{
  using Operation = T(*)(const T&, const T&);

  vector<vector<T>> st;
  Operation f;
  T identity;

  static constexpr int log2_floor(unsigned long long i) noexcept { return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1; }

  // Lazy loading constructor. Needs to call build!
  DisjointSparseTable(Operation op, const T neutral = T()) : st(), f(op), identity(neutral) {}

  DisjointSparseTable(vector<T> v) : DisjointSparseTable(v, F(min(a,b))) { }

  DisjointSparseTable(vector<T> v, Operation op, const T neutral = T()) : st(), f(op), identity(neutral)
  {
    build(v);
  }

  void build(vector<T> v)
  {
    st.resize(log2_floor(v.size())+1, vector<T>(1ll << (log2_floor(v.size())+1)));
    v.resize(st[0].size(), identity);
    for (int level = 0; level < (int)st.size(); ++level)
    {
      for (int block = 0; block < (1 << level); ++block)
      {
        const auto l = block << (st.size() - level);
        const auto r = (block + 1) << (st.size() - level);
        const auto m = l + (r - l) / 2;

        st[level][m] = v[m];
        for (int i = m + 1; i < r; i++)
          st[level][i] = f(st[level][i-1], v[i]);
        st[level][m-1] = v[m-1];
        for (int i = m-2; i >= l; i--)
          st[level][i] = f(st[level][i+1], v[i]);
      }
    }
  }

  T query(int l, int r) const
  {
    if (l > r) return identity;
    if (l == r) return st.back()[l];

    const auto k = log2_floor(l^r);
    const auto level = (int)st.size() - 1 - k;
    return f(st[level][l], st[level][r]);
  }
};

using S = GaussianElimination<20>;
S op(const S &a, const S &b)
{
  S c = a;
  c.merge(b);
  return c;
}

void solve()
{
  int n;
  cin >> n;
  vector<S> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i].insert(x);
  }
  HeavyLightDecomposition hld(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    hld.add_edge(u, v);
  }
  hld.build();

  DisjointSparseTable<S> seg(hld.segtree_rearrange(a), op);

  int q;
  cin >> q;
  while (q--) {
    int x, y, k;
    cin >> x >> y >> k;
    --x, --y;
    S ans;
    hld.for_each_vertex(x, y, [&](int l, int r) {
      ans = op(ans, seg.query(l, r));
    });
    cout << (ans.check(k) ? "YES" : "NO") << '\n';
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
