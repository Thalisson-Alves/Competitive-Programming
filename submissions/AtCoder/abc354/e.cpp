#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (auto &[a, b] : v) cin >> a >> b;

  vector<int> dp(1 << n, -1);
  auto nim = [&](auto &&self, int remain) -> int {
    auto &mex = dp[remain];
    if (~mex) return mex;
    set<int> seen;
    for (int i = 0; i < n; i++) if (remain >> i & 1) {
      for (int j = 0; j < n; j++) if (j != i and (remain >> j & 1)) {
        if (v[i].first == v[j].first or v[i].second == v[j].second) {
          seen.insert(self(self, remain ^ (1 << i) ^ (1 << j)));
        }
      }
    }
    mex = 0;
    for (auto x : seen) {
      if (mex == x) ++mex;
      else break;
    }
    return mex;
  };
  cout << (nim(nim, (1 << n) - 1) ? "Takahashi" : "Aoki") << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
