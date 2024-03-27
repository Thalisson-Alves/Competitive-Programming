#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

ll fpow(ll x, ll p) {
  ll res = 1;
  while (p) {
    if (p & 1) res *= x;
    p >>= 1;
    x *= x;
  }
  return res;
}

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
  int n, k;
  cin >> n >> k;
  constexpr ll mod = 1e9 + 7;
  ll res = 0, best = 0, total = 0;
  for (ll i = 0, x; i < n; i++) {
    cin >> x;
    best = max(best, res = max(res + x, 0ll));
    total += x;
  }
  best %= mod;
  total %= mod;
  ll sum = best * (fpow(2ll, k, mod) - 1) % mod;
  cout << (sum + total + mod) % mod << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}
