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
  ll n;
  cin >> n;
  vector<vector<ll>> dp(n+1, vector<ll>(2));
  for (ll i = 0; i < n; i++)
  {
    ll a, b; cin >> a >> b;
    dp[i+1] = dp[i];
    if (a == 1)
      dp[i+1][a] = max(dp[i][0] + b, dp[i][a]);
    else
      dp[i+1][a] = max({dp[i][0] + b, dp[i][1] + b, dp[i][a]});
  }
  cout << max({dp[n][0], dp[n][1]}) << '\n';
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

