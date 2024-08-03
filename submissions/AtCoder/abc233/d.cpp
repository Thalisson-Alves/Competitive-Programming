#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  map<ll, ll> mp;
  mp[0] = 1;
  ll pref = 0, res = 0;
  for (auto x : a) {
    pref += x;
    res += mp[pref-k];
    mp[pref]++;
  }
  cout << res << '\n';
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
