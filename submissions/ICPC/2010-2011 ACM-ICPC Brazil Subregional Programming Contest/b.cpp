#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  for (int n; cin >> n;) {
    vector<array<int, 2>> v(61, {0, 0});
    int res = 0;
    for (int i = 0; i < n; i++) {
      int x; char t;
      cin >> x >> t;
      auto d = t == 'D';
      if (v[x][d^1]) v[x][d^1]--, res++;
      else v[x][d]++;
    }
    cout << res << '\n';
  }
}

// clang-format off
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
