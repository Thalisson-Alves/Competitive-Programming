#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; cin >> n;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  if (n <= 3) {
    cout << accumulate(begin(a), end(a), 0, bit_or<int>()) << '\n';
    return;
  }
  ll res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        res = max(res, a[i]|a[j]|a[k]);
      }
    }
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
