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
  vector<int> v(n);
  int ones = 0;
  for (auto &x : v) cin >> x, ones += x == 1;
  if (ones) {
    cout << n - ones << '\n';
    return;
  }

  int res = INT_MAX;
  for (int i = 0; i < n; i++) {
    int g = v[i], j;
    for (j = i+1; j < n and g != 1; j++) {
      g = gcd(g, v[j]);
    }
    if (g == 1) {
      res = min(res, j - i - 1 + n - 1);
    }
  }

  cout << (res == INT_MAX ? -1 : res) << '\n';
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
