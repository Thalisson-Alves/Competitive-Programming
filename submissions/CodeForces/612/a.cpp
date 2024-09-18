#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, p, q;
  cin >> n >> p >> q;
  string s; cin >> s;
  int x = 0, y = -1;
  for (; x*p <= n; x++) {
    if ((n-x*p)%q == 0) {
      y = (n-x*p)/q;
      break;
    }
  }
  if (y == -1) {
    cout << "-1\n";
    return;
  }
  cout << x+y << '\n';
  for (int i = 0; i < x; i++) cout << s.substr(i*p, p) << '\n';
  for (int i = 0; i < y; i++) cout << s.substr(x*p+i*q, q) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
