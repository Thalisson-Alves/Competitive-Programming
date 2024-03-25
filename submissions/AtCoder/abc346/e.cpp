#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll n, m, q;
  cin >> n >> m >> q;

  vector<tuple<ll, ll, ll>> queries(q);
  for (auto &[t, a, x] : queries) {
    cin >> t >> a >> x;
    --a;
  }
  reverse(queries.begin(), queries.end());

  map<ll, ll> res;
  ll rows = 0, cols = 0, total = 0;
  vector<bool> row_used(n), col_used(m);
  for (auto [t, a, x] : queries) {
    if (t == 1 and !row_used[a] and cols < m) {
      res[x] += m - cols;
      total += m - cols;
      rows++;
      row_used[a] = 1;
    } else if (t == 2 and !col_used[a] and rows < n) {
      res[x] += n - rows;
      total += n - rows;
      cols++;
      col_used[a] = 1;
    }
  }
  if (total < n * m) {
    res[0] += n * m - total;
  }

  cout << res.size() << '\n';
  for (auto [a, b] : res)
    cout << a << ' ' << b << '\n';
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
