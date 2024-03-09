#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

void solve()
{
  string t;
  int n;
  cin >> t >> n;
  vector<vector<string>> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    while (x--) cin >> a[i].emplace_back();
  }

  const int inf = n+1;
  vector<vector<int>> memo(n, vector<int>(t.size(), -1));
  auto dp = [&](auto &&self, int i, string &cur) -> int {
    if (cur == t) return 0;
    if (i >= n or cur.size() >= t.size()) return inf;
    auto &res = memo[i][cur.size()];
    if (~res) return res;
    res = self(self, i+1, cur);
    for (const auto &s : a[i]) {
      if (s == t.substr(cur.size(), s.size())) {
        cur += s;
        res = min(res, self(self, i+1, cur) + 1);
        for (auto _ : s) cur.pop_back();
      }
    }
    return res;
  };

  string cur = "";
  auto res = dp(dp, 0, cur);
  cout << (res == inf ? -1 : res) << '\n';
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
