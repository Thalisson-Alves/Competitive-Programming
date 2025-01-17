#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  for (auto &[x, y] : v) cin >> x >> y;
  int qq;
  cin >> qq;
  while (qq--) {
    ll t, d;
    cin >> t >> d;
    --t;
    auto [q, r] = v[t];
    auto rem = d % q;
    if (rem == r) {
      cout << d << '\n';
    } else if (rem < r) {
      cout << d + (r - rem) << '\n';
    } else {
      cout << d + (q - rem + r) << '\n';
    }
  }
}

// x % q == r
// x >= d

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
