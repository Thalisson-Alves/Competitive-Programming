#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T> T fpow(T x, ll p) {
  T res = 1;
  while (p) {
    if (p & 1) res *= x;
    p >>= 1;
    x *= x;
  }
  return res;
}

void solve() {
  int n, k;
  cin >> n >> k;
  double res = 0;
  for (int i = 1; i <= k; i++)
    res += i * (fpow((double)i/k, n) - fpow((double)(i-1)/k, n));
  cout << fixed << setprecision(6) << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
