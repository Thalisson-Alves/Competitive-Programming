#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << k << '\n';
    return;
  }

  int x = (1 << (31 - __builtin_clz(k))) - 1;
  cout << x << ' ';
  cout << k - x << ' ';
  for (int i = 2; i < n; i++)
    cout << 0 << ' ';
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
