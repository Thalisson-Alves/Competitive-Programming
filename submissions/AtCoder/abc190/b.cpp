#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, s, d;
  cin >> n >> s >> d;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x < s and y > d) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
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
