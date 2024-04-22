#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  double dx, dy, dr;
  cin >> dx >> dy >> dr;
  constexpr int factor = 10000;
  ll x = llround(dx * factor);
  ll y = llround(dy * factor);
  ll r = llround(dr * factor);

  constexpr auto nxt = [](ll v) { return v + (factor - v%factor) % factor; };
  constexpr auto prv = [](ll v) { return v - (v % factor); };

  ll res = 0;
  for (ll i = nxt(x - r); i <= x + r; i += factor) {
    ll d = r*r - (i-x)*(i-x);
    assert(d >= 0);
    ll t = (ll)sqrt(d);
    ll low = prv(y - t) - factor * 2;
    for (int it = 0; it < 10 and (y-low)*(y-low) > d; it++, low += factor);
    ll high = prv(y + t) + factor * 2;
    for (int it = 0; it < 10 and (y-high)*(y-high) > d; it++, high -= factor);
    res += max((high - low) / factor + 1, 0ll);
  }
  cout << res << '\n';
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
