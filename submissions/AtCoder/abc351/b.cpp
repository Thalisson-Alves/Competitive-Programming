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
  vector<string> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != b[i][j]) {
        cout << i + 1 << ' ' << j + 1 << '\n';
      }
    }
  }
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
