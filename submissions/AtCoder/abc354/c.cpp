#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a) cin >> x >> y;
  vector<int> o(n);
  iota(o.begin(), o.end(), 0);
  sort(o.begin(), o.end(), [&](int i, int j) { return a[i].first > a[j].first; });
  int mn = INT_MAX;
  vector<int> res;
  for (auto i : o) {
    if (a[i].second < mn)
      res.push_back(i + 1);
    mn = min(a[i].second, mn);
  }
  cout << res.size() << '\n';
  sort(res.begin(), res.end());
  for (int i = 0; i < (int)res.size(); i++)
    cout << res[i] << " \n"[i == (int)res.size() - 1];
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
