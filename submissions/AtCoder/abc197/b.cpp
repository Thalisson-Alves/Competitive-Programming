#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  --x, --y;
  vector<string> v(n);
  for (auto &s : v) cin >> s;
  int res = 1;
  for (int i = x+1; i < n and v[i][y] != '#'; i++) res++;
  for (int i = x-1; ~i and v[i][y] != '#'; --i) res++;
  for (int i = y+1; i < m and v[x][i] != '#'; i++) res++;
  for (int i = y-1; ~i and v[x][i] != '#'; --i) res++;
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
