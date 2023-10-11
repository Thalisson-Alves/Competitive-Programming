#include <bits/stdc++.h>
#include <numeric>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ii = pair<int, int>;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
 
template<typename T> vector<T> split(const string &s);
ll fpow(ll x, ll p);
 
void solve()
{
  int n;
  cin >> n;
  vector<string> v(n);
  for (auto &x : v) cin >> x;

  vector<vector<ll>> dp(n, vector<ll>(n));
  dp[0][0] = v[0][0] != '*';
 
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (dp[i][j] or v[i][j] == '*') continue;
      auto up = (i > 0 ? dp[i-1][j] : 0);
      auto left = (j > 0 ? dp[i][j-1] : 0);
      dp[i][j] = (up + left) % ((ll)1e9+7);
    }
  }
  dbg(dp);
  cout << dp[n-1][n-1] << '\n';
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
 
template<typename T> vector<T> split(const string &s)
{
  vector<T> ans;
  stringstream ss(s);
  for (T x; ss >> x; ans.push_back(x));
  return ans;
}
 
ll fpow(ll x, ll p)
{
  if (p == 0) return 1;
  auto ans = fpow(x, p >> 1);
  ans *= ans;
  if (p & 1) ans *= x;
  return ans;
}

