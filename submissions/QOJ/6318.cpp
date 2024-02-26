#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  vector<vector<int>> dp(n + 1, vector<int>(10000, -1));
  auto knapsack = [&](auto &&self, int val, int i = 0) -> int {
    if (i == n) return 0;

    auto &memo = dp[i][val];
    if (~memo) return memo;

    auto s = to_string(val);
    sort(all(s));
    memo = 0;
    do {
      auto x = stoi(s);
      memo = max(memo, self(self, x, i + 1));
      if (x >= a[i]) {
        memo = max(memo, self(self, x - a[i], i+1) + 1);
      }
    } while (next_permutation(all(s)));
    return memo;
  };
  cout << knapsack(knapsack, k) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
