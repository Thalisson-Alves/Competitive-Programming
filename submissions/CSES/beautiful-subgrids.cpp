#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<bitset<3000>> v(n);
  for (auto &x : v) cin >> x;
  ll res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int x = (v[i]&v[j]).count();
      res += x * (x - 1) / 2;
    }
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
