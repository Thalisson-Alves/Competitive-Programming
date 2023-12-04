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
  vector<ll> basis;
  size_t size;

  GaussianElimination() : basis(Dim+1), size(0) {}

  void insert(ll x) {
    if (size == Dim) return;
    for (ll i = Dim; i >= 0; i--) {
      if ((x & 1ll << i) == 0) continue;

      if (!basis[i]) {
        basis[i] = x;
        size++;
        break;
      }

      x ^= basis[i];
    }
  }

  void merge(const GaussianElimination &other) {
    for (ll i = Dim; i >= 0; i--)
      if (size == Dim)
        break;
      else if (other.basis[i])
        insert(other.basis[i]);
  }

  void normalize() {
    for (ll i = Dim; i >= 0; i--)
      for (ll j = i - 1; j >= 0; j--)
        if (basis[i] & 1ll << j)
          basis[i] ^= basis[j];
  }

  bool check(ll x) const {
    for (ll i = Dim; i >= 0; i--) {
      if ((x & 1ll << i) == 0) continue;

      if (!basis[i])
        return false;

      x ^= basis[i];
    }

    return true;
  }

  auto operator[](ll k) const { return at(k); }

  ll at(ll k) const {
    ll ans = 0;
    ll total = 1ll << size;
    for (ll i = Dim; ~i; i--) {
      if (!basis[i]) continue;

      ll mid = total >> 1ll;
      if ((mid < k and (ans & 1ll << i) == 0) ||
          (k <= mid and (ans & 1ll << i)))
        ans ^= basis[i];

      if (mid < k)
        k -= mid;

      total >>= 1ll;
    }
    return ans;
  }

  ll at_normalized(ll k) const {
    ll ans = 0;
    k--;
    for (size_t i = 0; i <= Dim; i++) {
      if (!basis[i]) continue;
      if (k & 1) ans ^= basis[i];
      k >>= 1;
    }
    return ans;
  }

  ll max() const {
    return at(1ll << size);
  }
};

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T, auto op>
struct SegTree {
  static_assert(std::is_convertible_v<decltype(op), std::function<T(T, T)>>,
                "Operation must be convertible to std::function<T(T, T)>");

  int N;
  const T identity = T();
  vector<T> ns;

  SegTree(int n, const T identity_ = T()) : N(n), identity(identity_), ns(2 * N, identity)  {}

  SegTree(const vector<T> &v) : SegTree((int)v.size()) {
    copy(v.begin(), v.end(), ns.begin() + N);

    for (int i = N - 1; i > 0; --i)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }

  T query(size_t i) const {
    return ns[i + N];
  }

  T query(size_t l, size_t r) const {
    l = l + N;
    r = r + N;

    auto ml = identity, mr = identity;
    while (l <= r) {
      if (l & 1) ml = op(ml, ns[l++]);
      if (not (r & 1)) mr = op(ns[r--], mr);

      l >>= 1;
      r >>= 1;
    }

    return op(ml, mr);
  }

  void update(size_t i, T value) {
    set(i, op(ns[i + N], value));
  }

  void set(size_t i, T value) {
    auto a = i + N;

    ns[a] = value;
    while (a >>= 1)
      ns[a] = op(ns[2 * a], ns[2 * a + 1]);
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
  std::vector<int> aligned_id,
      aligned_id_inv;    // aligned_id[i] =  aligned id for vertex i (consecutive on heavy edges)
  std::vector<int> head; // head[i] = id of vertex on heavy path of vertex i, nearest to root
  std::vector<int> head_ids;      // consist of head vertex id's
  std::vector<int> heavy_path_id; // heavy_path_id[i] = heavy_path_id for vertex [i]


  HeavyLightDecomposition(const std::vector<std::vector<int>> &e, vector<int> roots = {0}) : HeavyLightDecomposition((int)e.size()) {
    this->e = e;
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

using Node = GaussianElimination<20>;
Node op(const Node &a, const Node &b)
{
  auto res = a;
  res.merge(b);
  return res;
}

void solve()
{
  int n;
  cin >> n;
  vector<Node> values(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    values[i].insert(x);
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  HeavyLightDecomposition hld(g);
  SegTree<Node, op> seg(hld.segtree_rearrange(values));

  int q;
  cin >> q;
  while (q--) {
    int x, y, k;
    cin >> x >> y >> k;
    --x, --y;
    Node ans;
    hld.for_each_vertex(x, y, [&](int l, int r) {
      ans.merge(seg.query(l, r));
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
