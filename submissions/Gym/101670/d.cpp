#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  map<int, set<int>> rows, cols;
  vector<pair<int, int>> pts;
  for (int n; cin >> n;) {
    rows.clear();
    cols.clear();
    pts.resize(n);
    for (auto &[x, y] : pts) {
      cin >> x >> y;
      rows[x].insert(y);
      cols[y].insert(x);
    }

    int res = 0;
    for (auto [x, y] : pts) {
      const auto &r = rows[x];
      const auto &c = cols[y];
      if (r.size() <= c.size()) {
        for (auto i = r.upper_bound(y + res); i != r.end(); i++) {
            auto l = *i - y;
            auto it = rows.find(x + l);
            if (it == rows.end()) continue;
            if (it->second.count(*i) and it->second.count(y))
              res = max(res, l);
        }
      } else {
        for (auto i = c.upper_bound(x + res); i != c.end(); i++) {
            auto l = *i - x;
            auto it = cols.find(y + l);
            if (it == cols.end()) continue;
            if (it->second.count(*i) and it->second.count(x))
              res = max(res, l);
        }
      }
    }
    cout << res << '\n';
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
