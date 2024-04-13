#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll l, r;
  cin >> l >> r;
  vector<pair<ll, ll>> res;
  if (!l) {
    ll nl = 1;
    while (nl <= r) {
      nl <<= 1;
    }
    nl >>= 1;
    res.emplace_back(l, nl);
    l = nl;
  }
  while (l < r) {
    auto tz = __builtin_ctzll(l);
    ll nl = l + 1;
    for (int i = 0; i <= tz; i++) {
      auto nxt = ((l >> i) + 1) << i;
      if (nxt <= r) nl = max(nl, nxt);
    }
    res.emplace_back(l, nl);
    l = nl;
  }
  cout << res.size() << '\n';
  for (auto [a, b] : res) {
    cout << a << ' ' << b << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
