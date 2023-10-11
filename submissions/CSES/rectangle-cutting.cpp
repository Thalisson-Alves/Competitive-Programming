#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

ll dfs(int a, int b, vector<vector<ll>> &dp) {
  if (a == b or a == 0 or b == 0) return 0;
  if (dp[a][b]) return dp[a][b];

  ll ans = INT_MAX;
  for (int i = 1; i <= a / 2; i++) {
    ans = min(ans, 1 + dfs(i, b, dp) + dfs(a - i, b, dp));
  }
  for (int i = 1; i <= b / 2; i++) {
    ans = min(ans, 1 + dfs(a, i, dp) + dfs(a, b-i, dp));
  }
  return dp[a][b] = dp[b][a] = ans;
}

void solve()
{
  int a, b;
  cin >> a >> b;
  vector<vector<ll>> dp(max(a, b) + 1, vector<ll>(max(a, b) + 1));
  cout << dfs(a, b, dp) << '\n';
  // dbg(dp);
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
