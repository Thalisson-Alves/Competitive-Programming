#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int tot = 0;
  for (int i = 0, tt = 1; i < n; i++) {
    int t, v;
    cin >> t >> v;
    while (tt < t) tt++, tot = max(tot-1, 0);
    tot += v;
  }
  cout << tot << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
