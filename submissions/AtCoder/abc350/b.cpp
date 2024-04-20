#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> v(n, 1);
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    v[--x]++;
  }

  int res = 0;
  for (auto x : v) res += x & 1;
  cout << res << '\n';
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
