#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, t, value, d, m;
  cin >> n >> t >> value >> d >> m;
  vector<int> bits(t);
  for (auto &x : bits) cin >> x;
  vector<int> first(d, -1);
  first[0] = 0;
  ll pref = 0;
  for (int k = 0;; k++) {
    (pref += value) %= d;
    if (~first[pref] and k - first[pref] + 1 >= m) {
      cout << first[pref] << ' ' << k << '\n';
      return;
    }
    if (first[pref] == -1)
      first[pref] = k + 1;

    int xo = 0;
    for (auto b : bits) {
      xo ^= (value >> b) & 1;
    }
    value >>= 1;
    value |= xo << (n - 1);
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
