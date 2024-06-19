#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int b, w;
  cin >> b >> w;
  set<pair<int, int>> vis;
  auto dfs = [&](auto &&self, int i, int j) {
    auto &x = ((i+j)&1 ? b : w);
    if (!x or !vis.emplace(i, j).second) return;
    --x;
    self(self, i+1, j);
    self(self, i, j+1);
    self(self, i-1, j);
    self(self, i, j-1);
  };
  dfs(dfs, 1e6, 1e6);
  if (w+b) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (auto [x, y] : vis) cout << x << ' ' << y << '\n';
  }
}

// clang-format off
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
