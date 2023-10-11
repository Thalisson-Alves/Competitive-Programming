#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

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

  T query(int l, int r) const
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

  T RMQ(int l, int r) const
  {
    auto lg = log2_floor(r-l+1);
    return f(st[lg][l], st[lg][r - (1 << lg) + 1]);
  }
};

struct LCA {
  vector<int> height, euler, first, ps;
  SparseTable<pair<int, int>> table;
 
  LCA(vector<vector<int>> &g, int root = 0) : height(g.size()), euler(g.size() * 2), first(g.size()), ps(g.size()), table(F(min(a,b)),{INT_MAX,INT_MAX}) {
    dfs(g, root, -1);
    int m = (int)euler.size();
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++) v[i] = {height[euler[i]], euler[i]};
    table.build(v);
  }
 
  void dfs(vector<vector<int>> &adj, int node, int p, int h = 0) {
    ps[node] = p;
    height[node] = h;
    first[node] = (int)euler.size();
    euler.push_back(node);
    for (auto to : adj[node]) {
      if (to != p) {
        dfs(adj, to, node, h + 1);
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

void dfs(const vector<vector<int>> &g, int u, int p, vector<ll> &vs) {
  for (auto x : g[u]) {
    if (x == p) continue;
    dfs(g, x, u, vs);
    vs[u] += vs[x];
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++){
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  LCA lca(g);
  vector<ll> vs(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    vs[u]++;
    vs[v]++;
    auto p = lca.lca(u, v);
    vs[p]--;
    if (lca.ps[p] >= 0) vs[lca.ps[p]]--;
  }

  dbg(lca.ps, vs);

  dfs(g, 0, -1, vs);

  for (int i = 0; i < n; i++)
    cout << vs[i] << " \n"[i == n-1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}

