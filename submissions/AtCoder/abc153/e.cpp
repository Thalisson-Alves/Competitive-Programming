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
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

ll knapsack(const vector<pair<ll, ll>> &v, ll w)
{
  vector<ll> dp(w+1, 1e18);
  dp[0] = 0;
  for (ll i = 1; i <= w; i++)
    for (auto [a, b] : v)
      dp[i] = min(dp[i], dp[max(i-a, 0ll)] + b);
  dbg(dp);
  return dp[w];
}

void solve()
{
  ll h, n;
  cin >> h >> n;
  vector<pair<ll, ll>> v(n);
  for (auto &[a, b] : v) cin >> a >> b;
  cout << knapsack(v, h) << '\n';
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
 
