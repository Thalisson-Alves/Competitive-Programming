#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

struct UFDS {
  vector<int> ps, sz;
  int components;
  UFDS(int n = 0) : ps(n), sz(n, 1), components(n) {
    iota(ps.begin(), ps.end(), 0);
  }
  int find(int x) { return (x == ps[x] ? x : (ps[x] = find(ps[x]))); }
  bool same(int x, int y) { return find(x) == find(y); }
  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    ps[y] = x;
    sz[x] += sz[y];
    --components;
    return true;
  }
  int add() {
    int id = (int)ps.size();
    ps.push_back(id);
    sz.push_back(1);
    ++components;
    return id;
  };
};

struct HLD {
  int V;
  int id;
  int nb_heavy_path;
  std::vector<std::vector<int>> g;
  std::vector<pair<int, int>> edges; // edges of the tree
  std::vector<int> par;         // par[i] = parent of vertex i (Default: -1)
  std::vector<int> depth;       // depth[i] = distance between root and vertex i
  std::vector<int> subtree_sz;  // subtree_sz[i] = size of subtree whose root is i
  std::vector<int> heavy_child; // heavy_child[i] = child of vertex i on heavy path (Default: -1)
  std::vector<int> tree_id;     // tree_id[i] = id of tree vertex i belongs to
  std::vector<int> aligned_id, aligned_id_inv;    // aligned_id[i] =  aligned id for vertex i (consecutive on heavy edges)
  std::vector<int> head; // head[i] = id of vertex on heavy path of vertex i, nearest to root
  std::vector<int> head_ids;      // consist of head vertex id's
  std::vector<int> heavy_path_id; // heavy_path_id[i] = heavy_path_id for vertex [i]


  HLD(const std::vector<std::vector<int>> &e, vector<int> roots = {0}) : HLD((int)e.size()) {
    g = e;
    build(roots);
  }
  HLD(int sz = 0)
      : V(sz), id(0), nb_heavy_path(0), g(sz), par(sz), depth(sz), subtree_sz(sz), heavy_child(sz),
        tree_id(sz, -1), aligned_id(sz), aligned_id_inv(sz), head(sz), heavy_path_id(sz, -1) {}

  void add_edge(int u, int v) {
    edges.emplace_back(u, v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  void _build_dfs(int root) {
    std::stack<std::pair<int, int>> st;
    par[root] = -1;
    depth[root] = 0;
    st.emplace(root, 0);
    while (!st.empty()) {
      int now = st.top().first;
      int &i = st.top().second;
      if (i < (int)g[now].size()) {
        int nxt = g[now][i++];
        if (nxt == par[now]) continue;
        par[nxt] = now;
        depth[nxt] = depth[now] + 1;
        st.emplace(nxt, 0);
      } else {
        st.pop();
        int max_sub_sz = 0;
        subtree_sz[now] = 1;
        heavy_child[now] = -1;
        for (auto nxt : g[now]) {
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
        for (int nxt : g[now])
          if (nxt != par[now] and nxt != heavy_child[now]) q.push(nxt);
      }
      nb_heavy_path++;
    }
  }

  void build(std::vector<int> roots = {0}) {
    int tree_id_now = 0;
    for (auto r : roots) _build_dfs(r), _build_bfs(r, tree_id_now++);
  }

  // data[i] = value of vertex i
  template <class T> std::vector<T> segtree_rearrange(const std::vector<T> &data) const {
    assert(int(data.size()) == V);
    std::vector<T> ret;
    ret.reserve(V);
    for (int i = 0; i < V; i++) ret.emplace_back(data[aligned_id_inv[i]]);
    return ret;
  }
  // data[i] = weight of edge[i]
  template <class T> std::vector<T> segtree_rearrange_weighted(const std::vector<T> &data) const {
    assert(data.size() == edges.size());
    vector<T> ret(V);
    for (int i = 0; i < (int)edges.size(); i++) {
      auto [u, v] = edges[i];
      if (depth[u] > depth[v]) swap(u, v);
      ret[aligned_id[v]] = data[i];
    }
    return ret;
  }

  int segtree_edge_index(int i) const {
    auto [u, v] = edges[i];
    if (depth[u] > depth[v]) swap(u, v);
    return aligned_id[v];
  }

  // query for vertices on path [u, v] (INCLUSIVE)
  void for_each_vertex(int u, int v, const auto &f) const {
    static_assert(std::is_invocable_r_v<void, decltype(f), int, int>);
    assert(tree_id[u] == tree_id[v] and tree_id[u] >= 0);
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
    assert(tree_id[from] == tree_id[to] and tree_id[from] >= 0);
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
    assert(tree_id[u] == tree_id[v] and tree_id[u] >= 0);
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
template <typename T, typename Op> struct SparseTable {
  vector<vector<T>> st;
  Op f;
  const T id;
  // Lazy loading constructor. Needs to call build!
  SparseTable(Op op, const T neutral = T()) : st(), f(op), id(neutral) {}
  SparseTable(const vector<T> &v, Op op = Op(), const T neutral = T()) : st(), f(op), id(neutral) { build(v); }
  void build(const vector<T> &v) {
    auto logn = 31-__builtin_clz((int)size(v));
    st.resize(logn+1, vector<T>(v.size()));
    st[0] = v;
    for (int i = 1; i <= logn; i++)
      for (int j = 0; j + (1 << i) <= (int)v.size(); j++)
        st[i][j] = f(st[i-1][j], st[i-1][j+(1 << (i-1))]);
  }
  T query(int l, int r) const {
    assert(l <= r);
    auto lg = 31-__builtin_clz(r-l+1);
    return f(st[lg][l], st[lg][r-(1<<lg)+1]);
  }
  // Non RMQ query
  T query_complete(int l, int r) const {
    assert(l <= r);
    T acc = id;
    for (int i = 31-__builtin_clz(size(st[0])); ~i; --i)
      if ((1 << i) <= r - l + 1) {
        acc = f(acc, st[i][l]);
        l += 1 << i;
      }
    return acc;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> es(m);
  for (auto &[u, v, w] : es) cin >> u >> v >> w, --u, --v;
  vector<int> o(m);
  iota(begin(o), end(o), 0);
  sort(begin(o), end(o), [&](int i, int j) { return es[i][2]<es[j][2]; });
  UFDS ufds(n);
  HLD hld(n);
  vector<int> cost;
  ll base = 0;
  for (auto i : o) if (ufds.join(es[i][0], es[i][1])) {
    cost.push_back(es[i][2]);
    hld.add_edge(es[i][0], es[i][1]);
    base += es[i][2];
  }
  hld.build();
  constexpr auto op = [](int a, int b) { return max(a, b); };
  SparseTable<int, decltype(op)> st(hld.segtree_rearrange_weighted(cost), op);
  for (auto [u, v, w] : es) {
    int mx = 0;
    hld.for_each_edge(u, v, [&](int l, int r) { mx = max(mx, st.query(l, r)); });
    cout << base + w-mx << '\n';
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
