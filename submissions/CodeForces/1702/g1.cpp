#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

/*
Used to define recursive lambdas,  first argument is the function itself

auto value = y_combinator([](auto &&gcd, int a, int b) -> int {
  return b ? gcd(b, a % b) : a;
});
*/
template <class Fun> class y_combinator_result {
  Fun fun_;

  public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T> struct SparseTable
{
  using Operation = T(*)(T, T);

  int LOGN;
  vector<vector<T>> st;
  Operation f;
  T identity;

  static constexpr int log2_floor(unsigned long long i) noexcept { return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1; }

  // Lazy loading constructor. Needs to call build!
  SparseTable(Operation op, const T neutral = T()) : LOGN(), st(), f(op), identity(neutral) {}

  SparseTable(const vector<T> &v) : SparseTable(v, F(max(a,b))) { }

  SparseTable(const vector<T> &v, Operation op, const T neutral = T()) : LOGN(), st(), f(op), identity(neutral)
  {
    build(v);
  }

  void build(const vector<T> &v)
  {
    LOGN = log2_floor(v.size());
    st.resize(LOGN+1, vector<T>(v.size()));

    st[0] = v;
    for (int i = 1; i <= LOGN; i++)
      for (int j = 0; j + (1 << i) <= (int)v.size(); j++)
        st[i][j] = f(st[i-1][j], st[i-1][j+(1 << (i-1))]);
  }

  // Non RMQ query
  T query_complete(int l, int r) const
  {
    T acc = identity;
    for (int i = LOGN; ~i; --i)
      if ((1 << i) <= r - l + 1)
      {
        acc = f(acc, st[i][l]);
        l += 1 << i;
      }
    return acc;
  }

  T query(int l, int r) const
  {
    auto lg = log2_floor(r-l+1);
    return f(st[lg][l], st[lg][r - (1 << lg) + 1]);
  }
};

struct LCA {
  vector<int> height, euler, first;
  SparseTable<pair<int, int>> table;

  LCA(vector<vector<int>> &g, int root = 0) : height(g.size()), euler(g.size() * 2), first(g.size()), table(F(min(a,b)),{INT_MAX,INT_MAX}) {
    vector<bool> visited(g.size());
    dfs(g, root, visited);
    int m = (int)euler.size();
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++) v[i] = {height[euler[i]], euler[i]};
    table.build(v);
  }

  void dfs(vector<vector<int>> &adj, int node, vector<bool> &visited, int h = 0) {
    visited[node] = true;
    height[node] = h;
    first[node] = (int)euler.size();
    euler.push_back(node);
    for (auto to : adj[node]) {
      if (!visited[to]) {
        dfs(adj, to, visited, h + 1);
        euler.push_back(node);
      }
    }
  }

  int lca(int u, int v) {
    int left = first[u], right = first[v];
    if (left > right) swap(left, right);
    auto x = table.query(left, right);
    return x.second;
  }
};

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> ds(n);
  y_combinator([&](auto &&dfs, int u, int p=-1) -> void {
    for (auto x : g[u]) if (x != p) {
      ds[x] = ds[u] + 1;
      dfs(x, u);
    }
  })(0);

  LCA lca(g);
  auto dist = [&](int a, int b) {
    return ds[a] + ds[b] - 2 * ds[lca.lca(a, b)];
  };

  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    vector<int> p(k);
    for (auto &x : p) cin >> x, --x;
    {
      auto f = *max_element(all(p), [&](auto a, auto b) { return ds[a] < ds[b]; });
      sort(all(p), [&](auto a, auto b) { return dist(a, f) < dist(b, f); });
    }

    ll d = 0;
    for (int i = 1; i < k; i++) d += dist(p[i], p[i-1]);
    if (d == dist(p.front(), p.back())) cout << "YES\n";
    else cout << "NO\n";
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
