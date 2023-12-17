#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n, q;
  cin >> n >> q;

  vector<pair<int, int>> queries(q);
  vector<bool> rows(n), cols(n);
  for (auto &[a, b] : queries) {
    cin >> a >> b;
    if (a == 1) cols[b] = 1;
    else rows[b] = 1;
  }

  ll res = (n-2) * (n-2);
  ll min_col = n, min_row = n;

  set<pair<int, int>> vis;
  for (auto [t, x] : queries) if (vis.emplace(t, x).second) {
    if (t == 1) {
      res -= min_row - 2;
      for (int i = x+1; i < min_col; i++) if (cols[i] and vis.emplace(t, i).second) {
        res -= min_row - 2;
      }
      min_col = x;
    } else {
      res -= min_col - 2;
      for (int i = x+1; i < min_row; i++) if (rows[i] and vis.emplace(t, i).second) {
        res -= min_col - 2;
      }
      min_row = x;
    }
  }
  cout << res << '\n';
}

int32_t main()
{
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
