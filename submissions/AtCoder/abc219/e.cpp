#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  constexpr int n = 4*4;
  int state = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    state |= x << i;
  }

  #define IDX(a, b) ((a * 4 + b))
  #define POS(a, b) (1 << IDX(a, b))

  constexpr int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  auto has_hole = [&](int msk, int s) {
    stack<pair<int, int>> st({{s / 4, s % 4}});
    int vis = 1 << s;
    while (!st.empty()) {
      auto [cx, cy] = st.top();
      st.pop();

      for (auto [dx, dy] : dir) {
        auto x = dx + cx;
        auto y = dy + cy;
        if (x < 0 or x >= 4 or y < 0 or y >= 4) return false;
        auto pos = POS(x, y);
        if (!(msk & pos) and !(vis & pos)) {
          st.emplace(x, y);
          vis |= pos;
        }
      }
    }
    return true;
  };
  auto hole = [&](int msk) {
    for (int i = 1; i < 3; i++) {
      for (int j = 1; j < 3; j++) {
        int s = IDX(i, j);
        if (!(msk & (1 << s))) {
          if (has_hole(msk, s)) return true;
        }
      }
    }
    return false;
  };
  auto good = [&](int msk) {
    if ((msk & state) != state) return false;
    int s = -1;
    for (int i = 0; i < n; i++) {
      if (msk & (1 << i)) {
        s = i;
        break;
      }
    }
    stack<pair<int, int>> st({{s / 4, s % 4}});
    int vis = 1 << s;
    while (!st.empty()) {
      auto [cx, cy] = st.top();
      st.pop();

      for (auto [dx, dy] : dir) {
        auto x = dx + cx;
        auto y = dy + cy;
        if (x < 0 or x >= 4 or y < 0 or y >= 4) continue;
        auto pos = POS(x, y);
        if ((msk & pos) and !(vis & pos)) {
          st.emplace(x, y);
          vis |= pos;
        }
      }
    }

    return vis == msk and !hole(msk);
  };

  int res = 0;
  for (int msk = 1; msk < (1 << n); msk++) {
    res += good(msk);
  }
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
