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
  ll x, y, z;
  cin >> x >> y >> z;
  string s;
  cin >> s;

  vector<vector<ll>> dp(s.size() + 1, vector<ll>(2, INT_MAX));
  dp[0][0] = 0;
  dp[0][1] = z;
  for (int i = 1; i <= (int)s.size(); i++)
  {
    if (s[i-1] == 'a')
    {
      dp[i][0] = min(dp[i-1][0] + x, dp[i-1][1] + y + z);
      dp[i][1] = min(dp[i-1][1] + y, dp[i-1][0] + z + x);
    }
    else
    {
      dp[i][0] = min(dp[i-1][0] + y, dp[i-1][1] + x + z);
      dp[i][1] = min(dp[i-1][1] + x, dp[i-1][0] + z + y);
    }
  }
  cout << min(dp.back()[0], dp.back()[1]) << '\n';
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

