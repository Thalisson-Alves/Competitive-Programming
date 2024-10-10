#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (auto &x : g) cin >> x;
  auto has = [&](int i, int j, int d) {
    if (i-d < 0 or i+d >= n or j-d < 0 or j+d >= m) return false;
    auto st = set<char>({g[i-d][j], g[i+d][j], g[i][j-d], g[i][j+d]});
    return st.size() == 1 and *st.begin() == '*';
  };

  set<tuple<int, int, int>> st;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) if (g[i][j] == '*') {
      int d;
      for (d = 1; has(i, j, d); d++);
      if (--d) st.emplace(i, j, d);
    }
  }

  vector<string> mat(n, string(m, '.'));
  for (auto [i, j, d] : st) {
    for (; ~d; d--)
      mat[i+d][j] = mat[i-d][j] = mat[i][j-d] = mat[i][j+d] = '*';
  }

  if (mat != g) {
    cout << "-1\n";
    return;
  }

  cout << st.size() << '\n';
  for (auto [i, j, d] : st) {
    cout << i+1 << ' ' << j+1 << ' ' << d << '\n';
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
