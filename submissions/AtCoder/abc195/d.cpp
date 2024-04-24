#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> v(n);
  for (auto &[a, b] : v) cin >> b >> a;
  sort(v.rbegin(), v.rend());

  vector<int> xs(m);
  for (auto &x : xs) cin >> x;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    map<int, int> hist;
    for (int i = 0; i < m; i++)
      if (i < l or i > r)
        hist[xs[i]]++;
    int res = 0;
    for (auto [value, cap] : v) {
      auto it = hist.lower_bound(cap);
      if (it == hist.end()) continue;
      res += value;
      if (!--it->second) hist.erase(it);
    }
    cout << res << '\n';
  }
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
