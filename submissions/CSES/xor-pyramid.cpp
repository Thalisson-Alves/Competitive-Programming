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
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  --n;
  for (int i = 0; n>>i; i++) if (n>>i&1) {
    for (int j = 0; j+(1<<i) < (int)size(a); j++)
      a[j]^=a[j+(1<<i)];
    a.resize(size(a)-(1<<i)+1);
  }
  cout << a[0] << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
