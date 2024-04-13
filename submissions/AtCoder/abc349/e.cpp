#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int mat[3][3];
  int got[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> mat[i][j];
      got[i][j] = 0;
    }
  }

  auto terminal = [&]() -> ll {
    {
      ll tak = 0, aok = 0;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (!got[i][j]) goto ct;
          if (got[i][j] > 0) tak += mat[i][j];
          else aok += mat[i][j];
        }
      }
      return tak - aok;
    }
  ct:
    for (int i = 0; i < 3; i++) {
      if (got[i][0] and got[i][1] == got[i][0] and got[i][0] == got[i][2]) return got[i][0] * (ll)LLONG_MAX;
      if (got[0][i] and got[1][i] == got[0][i] and got[0][i] == got[2][i]) return got[0][i] * (ll)LLONG_MAX;
    }
    if (got[0][0] and got[0][0] == got[1][1] and got[1][1] == got[2][2]) return got[1][1] * (ll)LLONG_MAX;
    if (got[0][2] and got[0][2] == got[1][1] and got[1][1] == got[2][0]) return got[1][1] * (ll)LLONG_MAX;
    return 0;
  };
  auto minimax = [&](auto &&self, int player) -> ll {
    {
      auto t = terminal();
      if (t) return t;
    }

    ll best_score = (~player ? -LLONG_MAX : LLONG_MAX);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (got[i][j]) continue;
        got[i][j] = player;
        auto value = self(self, -player);
        if (~player) best_score = max(best_score, value);
        else best_score = min(best_score, value);
        got[i][j] = 0;
      }
    }
    return best_score;
  };

  auto value = minimax(minimax, 1);
  assert(value);
  cout << (value > 0ll ? "Takahashi" : "Aoki") << '\n';
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
