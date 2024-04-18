#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll n, q, k;
  cin >> n >> q >> k;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;
  sort(v.begin(), v.end());
  ll res = 0;
  for (int i = 0; i < n; i++) {
    ll x = v[i] + (q - (v[i] % q)) % q;
    auto fst = lower_bound(v.begin(), v.end(), max(v[i], x + q * (k - 1)));
    auto lst = lower_bound(v.begin(), v.end(), x + q * k);
    res += lst - fst;
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
