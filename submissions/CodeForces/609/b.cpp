#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> hist(m);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    hist[--x]++;
  }
  ll res = 0;
  for (auto x : hist) {
    res += (x * (n-x));
    n -= x;
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
