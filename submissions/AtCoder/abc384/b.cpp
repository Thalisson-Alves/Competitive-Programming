#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, r;
  cin >> n >> r;
  int rng[][2] = {{1600, 2799}, {1200, 2399}};
  for (int i = 0; i < n; i++) {
    int d, a;
    cin >> d >> a;
    --d;
    if (clamp(r, rng[d][0], rng[d][1]) == r)
      r += a;
  }
  cout << r << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
