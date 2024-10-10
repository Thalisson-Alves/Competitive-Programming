#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  vector<vector<double>> dist(12, vector<double>(12));
  for (int i = 0; i < 12; i++) {
    for (int j = i+1; j < 12; j++) {
      dist[i][j] = dist[j][i] = hypot(i%3-j%3, i/3-j/3) / 30.0;
    }
  }
  constexpr auto convert = [&](char c) -> string {
    if (c == ' ') return string(1, '9' + 2);
    if (c <= 'r') return string((c-'a')%3+1, (c-'a')/3+1+'1');
    if (c == 's') return string(4, '7');
    if ('t' <= c and c <= 'v') return string(c-'t'+1, '8');
    return string(c-'w'+1, '9');
  };

  for (string s; getline(cin, s);) {
    string actual;
    for (auto c : s) {
      auto nxt = convert(c);
      if (actual.size() and actual.back() == nxt[0])
        actual.push_back('9' + 3);
      actual += nxt;
    }
    vector<vector<vector<double>>> memo(actual.size(), vector<vector<double>>(12, vector<double>(12)));
    auto dp = [&](auto &&self, int i, int d1, int d2) -> double {
      if (i >= (int)actual.size()) return 0;
      auto &res = memo[i][d1][d2];
      if (res) return res;
      auto pos = actual[i] - '1';
      return res = 0.2 + min(self(self, i+1, pos, d2) + dist[d1][pos],
                             self(self, i+1, d1, pos) + dist[d2][pos]);
    };
    cout << fixed << setprecision(2) << dp(dp, 0, 3, 5) << '\n';
  }
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
