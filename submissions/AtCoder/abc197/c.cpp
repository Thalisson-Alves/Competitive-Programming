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
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int res = INT_MAX;
  for (int mask = 0; mask < (1 << n); mask++) {
    int xs = 0, os = 0;
    for (int i = 0; i < n; i++) {
      os |= a[i];
      if (mask>>i&1) {
        xs ^= os;
        os = 0;
      }
    }
    res = min(res, xs^os);
  }
  cout << res << '\n';
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
