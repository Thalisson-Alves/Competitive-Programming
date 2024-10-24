#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int q;
  cin >> q;
  unordered_map<ll, ll> mp(q);
  while (q--) {
    int t; ll k;
    cin >> t >> k;
    if (t) cout << mp[k] << '\n';
    else cin >> mp[k];
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
