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
  vector<array<int, 2>> con(m);
  for (auto &[a, b] : con) cin >> a >> b;
  int k;
  cin >> k;
  vector<array<int, 2>> ps(k);
  for (auto &[a, b] : ps) cin >> a >> b;
  vector<bool> has(n);
  int res = 0;
  for (int i = 0; i < (1 << k); i++) {
    for (int j = 0; j < k; j++)
      has[ps[j][(i >> j) & 1]] = 1;
    int sum = 0;
    for (auto [a, b] : con) {
      sum += has[a] and has[b];
    }
    res = max(res, sum);
    has.assign(has.size(), 0);
  }
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
