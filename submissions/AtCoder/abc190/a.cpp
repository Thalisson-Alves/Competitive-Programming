#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c == 0) {
    cout << (a > b ? "Takahashi" : "Aoki") << '\n';
  } else {
    cout << (a >= b ? "Takahashi" : "Aoki") << '\n';
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
