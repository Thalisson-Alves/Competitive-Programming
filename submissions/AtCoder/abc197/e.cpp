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
  map<int, pair<int, int>> ids;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    auto it = ids.find(--b);
    if (it == ids.end())
      ids[b] = {a, a};
    else {
      auto &[mn, mx] = it->second;
      mn = min(mn, a);
      mx = max(mx, a);
    }
  }

  map<pair<int, int>, ll> memo;
  auto dp = [&](auto &&self, int x, auto it) -> ll {
    if (it == ids.end()) return abs(x);
    auto &res = memo[{x, it->first}];
    if (res) return res;
    auto [l, r] = it->second;
    auto d = r - l;
    return res = min(self(self, l, next(it)) + d + abs(r - x),
                     self(self, r, next(it)) + d + abs(x - l));
  };

  cout << dp(dp, 0, ids.begin()) << '\n';
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
