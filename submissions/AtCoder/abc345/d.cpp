#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve()
{
  int n, h, w;
  cin >> n >> h >> w;
  vector<pair<int, int>> sz(n);
  for (auto &[a, b] : sz) cin >> a >> b;

  vector<int> cur(h);
  int vis = 0;
  auto can = [&](int s, int i, int j) -> bool {
    auto [ch, cw] = sz[s];
    if (ch + i > h or cw + j > w) return false;
    int mask = ((1 << cw) - 1) << j;
    for (int a = 0; a < ch; a++) {
      if (cur[i+a] & mask) return false;
    }
    return true;
  };
  auto set = [&](int s, int i, int j, bool value) {
    auto [ch, cw] = sz[s];
    int mask = ((1 << cw) - 1) << j;
    for (int a = 0; a < ch; a++) {
      if (value)
        cur[a+i] |= mask;
      else
        cur[a+i] &= ~mask;
    }
    if (value) vis |= 1 << s;
    else vis &= ~(1 << s);
  };
  auto dfs = [&](auto &&self, int i, int j) -> bool {
    if (i == h) return 1;
    if (j == w) return self(self, i+1, 0);
    if (cur[i] & (1 << j)) return self(self, i, j+1);
    for (int s = 0; s < n; s++) if (!(vis & (1 << s))) {
      for (int t = 0; t < 2; t++) {
        if (can(s, i, j)) {
          set(s, i, j, 1);
          if (self(self, i, j+1)) return 1;
          set(s, i, j, 0);
        }
        swap(sz[s].first, sz[s].second);
      }
    }
    return 0;
  };
  cout << (dfs(dfs, 0, 0) ? "Yes" : "No") << '\n';
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
