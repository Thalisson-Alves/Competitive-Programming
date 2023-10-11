#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<vector<int>> dp(n, vector<int>(n));
  {
    vector<string> v(n);
    for (auto &x : v) cin >> x;
    dp[0][0] = v[0][0] == '*';
    for (int i = 1; i < n; i++)
    {
      dp[0][i] = dp[0][i-1] + (v[0][i] == '*');
      dp[i][0] = dp[i-1][0] + (v[i][0] == '*');
    }
    for (int i = 1; i < n; i++)
      for (int j = 1; j < n; j++)
        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (v[i][j] == '*');
  }

  for (auto x : dp)
  {
    dbg(x);
  }

#define sum(x,y) ((x>=0 and y>=0 ? dp[x][y] : 0))

  while (q--)
  {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    --y1, --x1, --y2, --x2;
    dbg(sum(y2,x2), sum(y1-1,x1), sum(y1,x1-1), sum(y1-1,x1-1));
    cout << sum(y2,x2) - sum(y1-1,x2) - sum(y2,x1-1) + sum(y1-1,x1-1) << '\n';
  }
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
