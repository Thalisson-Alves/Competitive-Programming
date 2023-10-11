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

ll dfs(const vector<vector<int>> &g, int u, int p, ll acc, const ll target, const vector<ll> &v, vector<int> &sz) {
  auto value = acc ^ v[u] ^ target;
  sz[u] = 1;
  ll ans = 0;
  for (auto x : g[u]) {
    if (x != p) {
      ans += dfs(g, x, u, acc ^ value, target, v, sz);
      sz[u] += sz[x];
    }
  }
  return ans + value * sz[u];
}

void dfs2(const vector<vector<int>> &g, int u, int p, const vector<ll> &v, const vector<int> &sz, vector<ll> &res, ll total) {
  dbg(u, p);
  res[u] = total;
  for (auto x : g[u]) if (x != p) {
    dfs2(g, x, u, v, sz, res, total + ((int)g.size() - 2 * sz[x]) * (v[u] ^ v[x]));
  }
}
 
void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> sz(n);
  vector<ll> res(n);
  dfs2(g, 0, -1, a, sz, res, dfs(g, 0, -1, 0, a[0], a, sz));

  for (auto x : res) {
    cout << x << ' ';
  }
  cout << '\n';
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}

