#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(n-1);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  ll res = INT_MAX, amount = 0, time = 0;
  for (int i = 0; i < n-1; i++) {
    res = min(res, time + (m-amount+a[i]-1) / a[i]);
    ll wait = max((b[i]-amount+a[i]-1)/a[i], 0ll);
    amount += wait * a[i] - b[i];
    time += wait + 1;
  }
  res = min(res, time + (m-amount+a.back()-1) / a.back());
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
