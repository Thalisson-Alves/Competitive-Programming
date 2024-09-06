#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  vector<pair<int, int>> c(m);
  for (auto &[x, y] : c) cin >> x >> y;
  auto f = [&](int mid) {
    int md = INT_MAX, mp = INT_MAX;
    for (int i = 0; i < mid; i++) {
      md = min(md, a[i]);
      mp = min(mp, b[i]);
    }
    vector<ll> costs(m);
    for (int i = 0; i < m; i++)
      costs[i] = c[i].second * 1ll * (c[i].first == 1 ? md : mp);
    sort(begin(costs), end(costs));
    ll sum = 0;
    for (int i = 0; i < k; i++)
      sum += costs[i];
    return sum <= s;
  };
  int l = 1, r = n;
  while (l <= r) {
    int mid = midpoint(l, r);
    if (f(mid)) r = mid-1;
    else l = mid+1;
  }
  if (l == n+1) {
    cout << "-1\n";
    return;
  }
  cout << l << '\n';
  int bd = -1, bp = -1;
  for (int i = 0; i < l; i++) {
    if (bd == -1 or a[bd] > a[i]) bd = i;
    if (bp == -1 or b[bp] > b[i]) bp = i;
  }
  vector<pair<int, int>> costs(m);
  for (int i = 0; i < m; i++)
    costs[i] = {c[i].second * 1ll * (c[i].first == 1 ? a[bd] : b[bp]), i};
  sort(begin(costs), end(costs));
  for (int i = 0; i < k; i++)
    cout << costs[i].second + 1 << ' ' << (c[costs[i].second].first == 1 ? bd : bp) + 1 << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
