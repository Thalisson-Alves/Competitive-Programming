#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int t, n, m;
  cin >> t >> n >> m;
  vector<pair<int, int>> segs(n);
  for (auto &[l, r] : segs) cin >> l >> r;
  sort(segs.begin(), segs.end());
  vector<int> us((ll)1e5+1, INT_MAX);
  for (int i = 0; i < m; i++) {
    int x, p;
    cin >> x >> p;
    us[x] = min(us[x], p);
  }

  auto need_umbrella = [&](int x) {
    auto it = upper_bound(segs.begin(), segs.end(), make_pair(x, INT_MAX));
    if (it == segs.begin()) return false;
    it = prev(it);
    return (it->first <= x and x + 1 <= it->second);
  };

  vector<vector<ll>> dp(2, vector<ll>(1e5+1, INT_MAX));
  dp[0][0] = 0;
  for (int i = 0; i <= t; i++) {
    auto need = need_umbrella(i);
    ll mn = LLONG_MAX;
    for (int w = 0; w < (int)dp[0].size(); w++) {
      mn = min(mn, dp[0][w]);
      dp[1][w] = dp[0][w] + w;
    }
    dp[1][0] = (need ? INT_MAX : mn);
    if (us[i] != INT_MAX) dp[1][us[i]] = min(dp[1][us[i]], mn + us[i]);
    swap(dp[0], dp[1]);
  }

  auto res = *min_element(dp[0].begin(), dp[0].end());
  cout << (res >= INT_MAX ? -1 : res) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
