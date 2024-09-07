#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;


void solve() {
  ll n;
  cin >> n;
  constexpr ll mod = 1e9+7;
  constexpr auto sum = [](ll l, ll r) { return (l + r) % mod * ((r - l + 1) % mod) % mod * 500000004 % mod; };
  ll res = 0;
  for (ll i = 1; i <= n;) {
    auto d = n/i;
    auto nxt = n/d+1;
    (res += sum(i, nxt-1) * (d%mod) % mod) %= mod;
    i = nxt;
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
