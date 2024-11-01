#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  ll res = 1;
  for (int i = 0; i < n-1; i+=2) {
    res = max(res, a[i+1]-a[i]);
  }
  if (~n&1) {
    cout << res << '\n';
    return;
  }
  vector<ll> pref(n/2+1, 1), suf(n/2+1, 1);
  for (int i = 0; i*2+1 < n; i++) {
    pref[i+1] = max(pref[i], a[i*2+1]-a[i*2]);
    rbegin(suf)[i+1] = max(rbegin(suf)[i], rbegin(a)[i*2]-rbegin(a)[i*2+1]);
  }
  for (int i = 0; i <= n/2; i++)
    res = min(res, max(pref[i], suf[i]));
  cout << max(res, 1ll) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
