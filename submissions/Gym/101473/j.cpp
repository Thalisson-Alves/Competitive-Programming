#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T> struct SparseTable
{
  using Operation = T(*)(T, T);

  int LOGN;
  vector<vector<T>> st;
  Operation f;
  T identity;

  static constexpr int log2_floor(unsigned long long i) noexcept { return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1; }

  SparseTable(Operation op, const T neutral = T()) : LOGN(), st(), f(op), identity(neutral) {}

  SparseTable(const vector<T> &v, Operation op, const T neutral = T()) : LOGN(), st(), f(op), identity(neutral)
  {
    build(v);
  }

  SparseTable(const vector<T> &v) : SparseTable(v, F(max(a,b))) { }

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
  vector<int> height, euler, first;
  SparseTable<pair<int, int>> table;
 
  LCA(vector<vector<int>> &g, int root = 0) : height(g.size()), euler(g.size() * 2), first(g.size()), table(F(min(a,b)),{INT_MAX,INT_MAX}) {
    vector<bool> visited(len(g));
    dfs(g, root, visited);
    int m = (int)euler.size();
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++) v[i] = {height[euler[i]], euler[i]};
    table.build(v);
  }
 
  void dfs(vector<vector<int>> &adj, int node, vector<bool> &visited, int h = 0) {
    visited[node] = true;
    height[node] = h;
    first[node] = len(euler);
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
  int n, m, q;
  cin >> n >> m >> q;
  vector<tuple<ll, int, int>> edges;
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    edges.emplace_back(c, a, b);
    edges.emplace_back(c, b, a);
  }
 
  vector<vector<int>> g(n);
  vector<ll> values(n, INT_MAX);
  {
    const int mx = 3e5;
    vector<int> ps(mx);
    iota(all(ps), 0);
    function<int(int)> find_parent = [&](int x) -> int {
      return (x == ps[x] ? x : (ps[x] = find_parent(ps[x])));
    };
 
    sort(all(edges), greater<>());
    for (auto [c, a, b] : edges)
    {
      auto pa = find_parent(a);
      auto pb = find_parent(b);
      if (pa == pb)
        continue;
 
      ps[pa] = ps[pb] = len(g);
 
      g.push_back({pa, pb});
      values.push_back(c);
    }
  }
  dbg(g);
  dbg(values);
 
  LCA st(g, len(g) -1);
 
  while (q--)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    cout << values[st.lca(a, b)] << '\n';
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
