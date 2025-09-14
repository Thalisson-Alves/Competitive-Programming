#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  vector<vector<int>> dp(n, vector<int>(m));
  auto f = [&](int i, int j) { return (~i and ~j ? dp[i][j] : 0); };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i][j] = max({f(i-1, j-1) + (a[i] == b[j]), f(i-1, j), f(i, j-1)});
    }
  }
  vector<int> res;
  res.reserve(dp.back().back());
  for (int i = n-1, j = m-1; ~i and ~j;) {
    int dc = dp[i][j], di = f(i-1,j), dj = f(i,j-1), dij = f(i-1,j-1);
    if (dc != di and di == dj and di == dij) res.push_back(a[i--]), --j;
    else if (di > dj) --i;
    else --j;
  }
  reverse(res.begin(), res.end());
  cout << res.size() << '\n';
  for (int i = 0; i < (int)res.size(); i++)
    cout << res[i] << " \n"[i == (int)res.size()-1];
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
