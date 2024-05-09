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
  int win = -1, cnt = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (cnt < x) {
      win = i;
      cnt = x;
    }
  }
  cout << "NS"[win == 0] << '\n';
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
