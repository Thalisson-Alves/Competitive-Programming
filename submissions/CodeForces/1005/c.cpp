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
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  int res = 0;
  for (int i = 0; i < n; i++) {
    bool found = 0;
    for (ll j = 1; !found and j <= 3 * a.back(); j <<= 1) {
      auto [l, r] = equal_range(a.begin(), a.end(), j - a[i]);
      found |= (r - l and (l - a.begin() != i or r - l > 1));
    }
    res += not found;
  }
  cout << res << '\n';
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
