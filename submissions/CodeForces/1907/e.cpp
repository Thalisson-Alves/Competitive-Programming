#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

int dp[10] = {};
void pre() {
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      for (int k = 0; k < 10; k++)
        if (i+j+k < 10) dp[i+j+k]++;
}

void solve()
{
  int n;
  cin >> n;

  ll res = 1;
  while (n) {
    auto [d, r] = div(n, 10);
    res *= dp[r];
    n = d;
  }
  cout << res << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  pre();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
