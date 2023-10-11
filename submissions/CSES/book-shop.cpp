#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll oo = 1e18;

void solve()
{
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> bs(n);
  for (auto &[a, _] : bs) cin >> a;
  for (auto &[_, a] : bs) cin >> a;

  vector<vector<int>> dp(n+1, vector<int>(x+1));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= x; j++)
    {
      dp[i][j] = dp[i-1][j];

      auto [w, v] = bs[i-1];
      if (w <= j)
        dp[i][j] = max(v + dp[i-1][j-w], dp[i][j]);
    }
  }

  cout << dp[n][x] << '\n';
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
