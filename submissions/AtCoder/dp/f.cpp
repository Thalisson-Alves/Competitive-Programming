#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  string s, t;
  cin >> s >> t;

  vector<vector<int>> ps(26), pt(26);
  for (int i = 0; i < (int)s.size(); i++) ps[s[i]-'a'].push_back(i);
  for (int i = 0; i < (int)t.size(); i++) pt[t[i]-'a'].push_back(i);

  vector<vector<int>> memo(s.size() + 1, vector<int>(t.size() + 1, -1));
  vector<vector<pair<int, int>>> to(s.size() + 1, vector<pair<int, int>>(t.size() + 1, {-1, -1}));
  auto dp = [&](auto &&self, int i, int j) -> int {
    auto &res = memo[i+1][j+1];
    if (~res) return res;
    int val = 0;
    for (int c = 0; c < 26; c++) {
      auto is = upper_bound(ps[c].begin(), ps[c].end(), i);
      if (is == ps[c].end()) continue;
      auto it = upper_bound(pt[c].begin(), pt[c].end(), j);
      if (it == pt[c].end()) continue;
      auto x = self(self, *is, *it) + 1;
      if (val < x) {
        val = x;
        to[i+1][j+1] = {*is+1, *it+1};
      }
    }
    return res = val;
  };
  dp(dp, -1, -1);

  pair<int, int> cur;
  string res;
  while (1) {
    auto nxt = to[cur.first][cur.second];
    if (nxt.first == -1) break;
    res += s[nxt.first-1];
    cur = nxt;
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
