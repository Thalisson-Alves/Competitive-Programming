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
  vector<pair<int, bool>> es(2*n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    es[i<<1] = {a, 0};
    es[i<<1|1] = {b, 1};
  }
  sort(begin(es), end(es));
  vector<pair<int, int>> res;
  int open = 0;
  for (auto [a, b] : es) {
    if (b) {
      if (open-- == k) res.back().second = a;
    } else {
      if (++open == k) res.emplace_back(a, -1);
    }
  }
  cout << size(res) << '\n';
  for (auto [a, b] : res) cout << a << ' ' << b << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
