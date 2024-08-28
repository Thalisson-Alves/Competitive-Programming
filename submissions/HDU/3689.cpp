#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

vector<int> kmp(const string &p) {
  int m = (int)p.size(), t = -1;
  vector<int> bs(m + 1, -1);

  for (int i = 1; i <= m; i++) {
    for (; t > -1 and p[t] != p[i - 1]; t = bs[t]);
    ++t;
    bs[i] = (i == m or p[t] != p[i]) ? t : bs[t];
  }

  return bs;
}

void solve() {
  for (int n, m; cin >> n >> m, n|m;) {
    vector<pair<char, double>> v(n);
    for (auto &[a, b] : v) cin >> a >> b;
    string s; cin >> s;
    auto bs = kmp(s);
    vector<vector<double>> memo(m, vector<double>(size(s), -1));
    auto dp = [&](auto &&self, int i, int j) -> double {
      if (j == (int)size(s)) return 100;
      if (i >= m) return 0;
      auto &res = memo[i][j];
      if (res >= 0) return res;
      res = 0;
      for (auto [c, p] : v) {
        if (c == s[j]) res += self(self, i+1, j+1) * p;
        else {
          int nj = j;
          while (nj >= 0 and s[nj] != c) nj = bs[nj];
          res += self(self, i+1, nj+1) * p;
        }
      }
      return res;
    };
    cout << fixed << setprecision(2) << dp(dp, 0, 0) << "%\n";
  }
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
