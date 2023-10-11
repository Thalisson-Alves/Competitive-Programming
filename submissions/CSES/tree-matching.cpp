#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void dfs(const vector<vector<int>> &g, int u, int p, vector<int> &sz) {
  sz[u] = 1;
  for (auto x : g[u])
    if (x != p) {
      dfs(g, x, u, sz);
      sz[u] += sz[x];
    }
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<char> vis(n);
  vector<int> sz(n);
  dfs(g, 0, -1, sz);
  dbg(sz);
  auto cmp = [&](auto i, auto j) {
    return sz[i] > sz[j];
  };
  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
  for (int i = 0; i < n; i++)
    pq.push(i);

  int ans = 0;
  while (not pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    if (vis[cur]) continue;

    int con = -1;
    for (auto x : g[cur]) {
      if (not vis[x]) {
        con = x;
        break;
      }
    }

    if (con == -1) continue;
    ans++;
    vis[con] = vis[cur] = 1;
    dbg(con, cur);
  }

  cout << ans << '\n';
}

int32_t main()
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
