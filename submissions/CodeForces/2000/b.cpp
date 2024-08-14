#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n; cin >> n;
  vector<bool> has(n+2);
  bool res = 1;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    has[x] = 1;
    res &= i == 0 or has[x+1] or has[x-1];
  }
  cout << (res ? "YES" : "NO") << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
