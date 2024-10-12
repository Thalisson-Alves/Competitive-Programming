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
  ll total = 0;
  for (auto &[a, b] : v) cin >> a >> b, total += b;
  if (total%3) {
    cout << "-1\n";
    return;
  }
  total /= 3;
  vector<int> pref(n);
  pref[0] = v[0].second;
  for (int i = 1; i < n; i++) pref[i] = v[i].second + pref[i-1];
  vector<vector<vector<int>>> memo(n, vector<vector<int>>(total+1, vector<int>(total+1, -1)));
  auto dp = [&](auto &&self, int i, int s1, int s2) -> int {
    if (i >= n) return 0;
    auto &res = memo[i][s1][s2];
    if (~res) return res;
    res = n+1;
    if (pref[i]-s1-s2 <= total) res = min(res, self(self, i+1, s1, s2) + (v[i].first != 3));
    if (s1+v[i].second<=total) res = min(res, self(self, i+1, s1+v[i].second, s2) + (v[i].first != 1));
    if (s2+v[i].second<=total) res = min(res, self(self, i+1, s1, s2+v[i].second) + (v[i].first != 2));
    return res;
  };
  auto res = dp(dp, 0, 0, 0);
  cout << (res > n ? -1 : res) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
