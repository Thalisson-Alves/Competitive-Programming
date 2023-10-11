#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T, auto op>
struct SegTree {
  static_assert(std::is_convertible_v<decltype(op), std::function<T(T, T)>>,
                "Operation must be convertible to std::function<T(T, T)>");

  int N;
  const T identity = T();
  vector<T> ns;

  SegTree() : SegTree(0) {}
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
  vector<int> parent, depth, size, heavy, head, pos;

  static ll op(ll a, ll b) { return a + b; }
  SegTree<ll, op> seg;

  HeavyLightDecomposition(const vector<vector<int>> &g, const vector<int> &v, int root=0) : parent(g.size()), depth(g.size()), size(g.size()), heavy(g.size(), -1), head(g.size()), pos(g.size()), seg((int)g.size()) {
    dfs(g, root);
    int cur_pos = 0;
    decompose(g, root, root, cur_pos);

    for (int i = 0; i < (int)g.size(); i++) {
      seg.set(pos[i], v[i]);
    }
  }

  ll query_path(int a, int b) const {
    ll res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
      if (depth[head[a]] > depth[head[b]])
        swap(a, b);
      res = op(res, seg.query(pos[head[b]], pos[b]));
    }
    if (depth[a] > depth[b])
      swap(a, b);
    return op(res, seg.query(pos[a], pos[b]));
  }

  ll query_subtree(int a) const {
    return seg.query(pos[a], pos[a]+size[a]-1);
  }

  void set(int a, int x) {
    seg.set(pos[a], x);
  }

private:
  void dfs(const vector<vector<int>> &g, int u) {
    size[u] = 1;
    int mx_child_size = 0;
    for (auto x : g[u]) if (x != parent[u]) {
      parent[x] = u;
      depth[x] = depth[u] + 1;
      dfs(g, x);
      size[u] += size[x];
      if (size[x] > mx_child_size)
        mx_child_size = size[x], heavy[u] = x;
    }
  }

  void decompose(const vector<vector<int>> &g, int u, int h, int &cur_pos) {
    head[u] = h;
    pos[u] = cur_pos++;
    if (heavy[u] != -1)
      decompose(g, heavy[u], h, cur_pos);

    for (auto x : g[u]) if (x != parent[u] and x != heavy[u]) {
      decompose(g, x, x, cur_pos);
    }
  }
};

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  HeavyLightDecomposition hld(g, a);
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      int y;
      cin >> y;
      hld.set(x-1, y);
    } else {
      cout << hld.query_subtree(x-1) << '\n';
    }
  }
}
 
int main()
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

