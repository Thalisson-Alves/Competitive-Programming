#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> pts(n);
  for (int i = 0; i < n*m; i++) {
    int x;
    cin >> x;
    pts[i%n] += x;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (pts[i] >= pts[res])
      res = i;
  }
  cout << res + 1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
