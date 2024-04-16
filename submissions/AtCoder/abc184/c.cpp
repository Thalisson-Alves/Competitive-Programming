#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = c - a;
  int y = d - b;
  if (!x and !y) {
    cout << "0\n";
  } else if (x == y or x == -y or abs(x) + abs(y) <= 3) {
    cout << "1\n";
  } else if ((x + y) % 2 == 0 or abs(x) + abs(y) <= 6 or abs(x + y) <= 3 or abs(x - y) <= 3) {
    cout << "2\n";
  } else {
    cout << "3\n";
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
