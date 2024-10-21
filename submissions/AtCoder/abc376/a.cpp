#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, c;
  cin >> n >> c;
  int res = 0, last = -1e8;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    if (t-last >= c) {
      res++;
      last = t;
    }
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
