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
  vector<vector<int>> board(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      board[i][j] = (c == '.') - 1;
    }
  }
  auto hash = [&]() {
    auto h = 0ull;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 2)
          h |= 1ull << (i * n + j);
      }
    }
    return h;
  };

  constexpr int dir4[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  auto can = [&](int i, int j, int remain) {
    if (board[i][j]) return false;
    if (remain == k) return true;
    for (auto [dx, dy] : dir4) {
      auto x = i + dx;
      auto y = j + dy;
      if (0 <= x and x < n and 0 <= y and y < n and board[x][y] == 2)
        return true;
    }
    return false;
  };

  set<unsigned long long> vis;
  auto cur_hash = hash();
  int res = 0;
  auto dfs = [&](auto &&self, int remain) {
    if (!vis.insert(cur_hash).second) return;
    if (!remain) {
      ++res;
      return;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (can(i, j, remain)) {
          board[i][j] = 2;
          cur_hash ^= 1ull << (i * n + j);
          self(self, remain - 1);
          cur_hash ^= 1ull << (i * n + j);
          board[i][j] = 0;
        }
      }
    }
  };
  dfs(dfs, k);
  cout << res << '\n';
}

// clang-format off
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
