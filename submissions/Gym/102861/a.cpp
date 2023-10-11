#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n, a, b;
  cin >> n >> a >> b;

  bool is_zero = !a;
  a = max(a, 1);

  vector<double> dp(n+1, (is_zero ? 1.0 * (b - a + 2) / (b - a + 1) : 1.0));
  dp[n] = 0;
  double sum = 0;
  int sum_idx = n;

  for (int i = n-1; ~i; --i)
  {
    if (i + b < sum_idx)
      sum -= dp[sum_idx--];
    if (i + a < n)
      sum += dp[i+a];

    dp[i] += sum / (b - a + 1);
  }

  cout << fixed << setprecision(7) << dp[0] << '\n';
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
