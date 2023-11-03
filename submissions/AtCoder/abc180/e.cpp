#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

ll tsp(int i, int mask, const vector<vector<ll>> &dist, vector<vector<ll>> &memo)
{
  if (mask == (1 << dist.size()) - 1)
    return dist[i][0];

  if (memo[i][mask] != -1)
    return memo[i][mask];

  ll ans = 1e18;
  for (int j = 0; j < (int)dist.size(); j++)
  {
    if (mask & (1 << j))
      continue;

    ans = min(ans, tsp(j, mask | (1 << j), dist, memo) + dist[i][j]);
  }

  return memo[i][mask] = ans;
}

ll tsp(int i, const vector<vector<ll>> &dist) {
  vector<vector<ll>> memo(dist.size(), vector<ll>(1ll << dist.size(), -1));
  return tsp(i, 1ll << i, dist, memo);
}

void solve()
{
  int n;
  cin >> n;
  vector<array<int, 3>> v(n);
  for (auto &x : v) for (auto &y : x) cin >> y;

  vector<vector<ll>> dist(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = abs(v[j][0] - v[i][0]) + abs(v[j][1] - v[i][1]) + max(0, v[j][2] - v[i][2]);
    }
  }

  cout << tsp(0, dist) << '\n';
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
