#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> pos(20);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    pos[--x].push_back(i);
  }
  vector<int> dep(1<<20);
  for (int i = 0; i < 1<<20; i++) dep[i] = __builtin_popcount(i);
  vector<int> dp(1<<20, n);
  dp[0] = 0;
  queue<int> q({0});
  while (!q.empty()) {
    auto msk = q.front();
    q.pop();
    for (int i = 0; i < 20; i++) {
      if (msk >> i & 1) {
        int x = dp[msk^(1<<i)];
        auto it = lower_bound(begin(pos[i]), end(pos[i]), x);
        if (it != end(pos[i])) ++it;
        if (it != end(pos[i])) dp[msk] = min(dp[msk], *it);
      } else if (--dep[msk^(1<<i)] == 0) {
        q.push(msk^(1<<i));
      }
    }
  }
  int res = 0;
  for (int i = 0; i < 1<<20; i++) {
    if (dp[i] < n) res = max(res, 2*__builtin_popcount(i));
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
