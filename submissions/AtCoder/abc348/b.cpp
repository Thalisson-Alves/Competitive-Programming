#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  for (auto &[x, y] : v) cin >> x >> y;
  auto dist = [&](int i, int j) {
    auto [ax, ay] = v[i];
    auto [bx, by] = v[j];
    return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
  };
  for (int i = 0; i < n; i++) {
    ll best = -1, best_dist = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      auto d = dist(i, j);
      if (best_dist < d) {
        best = j;
        best_dist = d;
      }
    }
    cout << best + 1 << '\n';
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
