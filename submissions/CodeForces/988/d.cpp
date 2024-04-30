#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  vector<ll> res{a[0]};
  for (int i = 0; i < n; i++) {
    for (ll d = 1; d <= (ll)1e11; d <<= 1) {
      auto fl = binary_search(a.begin(), a.end(), a[i] - d);
      auto fr = binary_search(a.begin(), a.end(), a[i] + d);
      if (fl and fr) {
        res = {a[i]-d, a[i], a[i]+d};
      } else if (fl and res.size() < 2) {
        res = {a[i]-d, a[i]};
      } else if (fr and res.size() < 2) {
        res = {a[i], a[i]+d};
      }
    }
  }

  cout << res.size() << '\n';
  for (auto x : res) cout << x << ' ';
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
