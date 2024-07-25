#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  ll res = LLONG_MIN;
  for (int i = max(0, n-k-3); i < n; i++) {
    for (int j = i+1; j < n; j++) {
      res = max(res, 1ll*(i+1)*(j+1)-1ll*k*(a[i]|a[j]));
    }
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
