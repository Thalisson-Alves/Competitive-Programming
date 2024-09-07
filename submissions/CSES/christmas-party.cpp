#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

ll fpow(ll x, ll p, ll mod) {
  ll res = 1;
  while (p) {
    if (p & 1) res = res * x % mod;
    p >>= 1;
    x = x * x % mod;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  constexpr int mod = 1e9 + 7;
  vector<ll> fat(n+1);
  fat[0] = 1;
  for (int i = 1; i <= n; i++) fat[i] = fat[i-1] * i % mod;
  auto comb = [&](int a, int b) { return fat[a] * fpow(fat[a-b] * fat[b] % mod, mod - 2, mod) % mod; };
  ll res = fat[n];
  for (int i = 1; i <= n; i++) {
    ((res += (i&1 ? -1 : 1) * comb(n, i) * fat[n-i] % mod) += mod) %= mod;
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
