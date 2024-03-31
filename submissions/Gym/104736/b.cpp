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
  map<int, int> mp;
  for (int i = 0; i < 3 * n; i++) {
    int x;
    cin >> x;
    mp[x]++;
  }
  bool win = 0;
  for (auto [_, x] : mp) {
    if (x % 3) {
      win = 1;
      break;
    }
  }
  cout << "NY"[win] << '\n';
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
