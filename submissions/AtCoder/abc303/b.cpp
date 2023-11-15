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
ll oo = 1e18;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(m, vector<int>(n));
  for (auto &x : v) for (auto &y : x) cin >> y;
  set<pair<int, int>> po;
  for (int i = 0 ; i < m; i++)
    for (int j = 1; j < n; j++)
      po.insert(minmax(v[i][j], v[i][j-1]));

  ll ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i+1; j <= n; j++)
      ans += not po.count({i, j});
  cout << ans << '\n';
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

