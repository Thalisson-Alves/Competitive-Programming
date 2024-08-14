#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

void solve() {
  int n;
  cin >> n;
  double res = 3.5;
  for (int i = 1; i < n; i++) {
    double sum = 0;
    for (int j = 1; j <= 6; j++) sum += max(1.0 * j, res) / 6.0;
    res = sum;
  }
  cout << fixed << setprecision(7) << res << '\n';
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
