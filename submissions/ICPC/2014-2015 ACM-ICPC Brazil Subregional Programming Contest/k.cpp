#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<int> pos(s.size());
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    pos[--x] = 1;
  }

  using T = pair<int, int>;
  vector<vector<T>> memo(s.size(), vector<T>(s.size()));
  for (int i = 0; i < (int)s.size(); i++) memo[i][i] = {pos[i], 1};
  auto dp = [&](auto &&self, int i, int j) -> T {
    if (i > j) return {0, 0};
    auto &res = memo[i][j];
    if (res.second) return res;

    res = max(self(self, i+1, j), self(self, i, j-1));
    if (s[i] == s[j]) {
      auto [special, size] = self(self, i+1, j-1);
      res = max(res, {special + pos[i] + pos[j], size + 2});
    }
    return res;
  };

  cout << dp(dp, 0, (int)s.size()-1).second << '\n';
}

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
