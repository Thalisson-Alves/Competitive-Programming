#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, c, t;
  cin >> n >> c >> t;
  vector<int> ps(n);
  for (auto &x : ps) cin >> x;
  auto f = [&](ll k) -> bool {
    int cnt = 1, sum = 0;
    for (auto p : ps) {
      sum += p;
      if (sum > 1ll * k * t) {
        cnt++;
        sum = p;
      }
    }
    return cnt <= c;
  };
  int l = (*max_element(ps.begin(), ps.end()) + t - 1) / t, r = 1e9;
  while (l <= r) {
    auto m = midpoint(l, r);
    (f(m) ? r = m - 1 : l = m + 1);
  }
  cout << l << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
