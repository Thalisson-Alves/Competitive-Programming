#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());

  while (q--) {
    int b, k;
    cin >> b >> k;
    ll l = 0, r = LLONG_MAX;
    while (l <= r) {
      auto mid = midpoint(l, r);
      auto it = lower_bound(a.begin(), a.end(), b-mid);
      auto jt = upper_bound(a.begin(), a.end(), b+mid);
      if (jt-it < k) l = mid + 1;
      else r = mid - 1;
    }
    cout << l << '\n';
  }
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
