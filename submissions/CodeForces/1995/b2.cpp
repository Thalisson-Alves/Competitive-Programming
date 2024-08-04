#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  map<int, ll> mp;
  for (int i = 0; i < n; i++) {
    int x; cin >> x; mp[v[i]] = x;
  }
  ll res = 0;
  for (auto [x, y] : mp) {
    auto cnt = min(m / x, y);
    auto it = mp.find(x+1);
    auto mx = (it == mp.end() ? 0 : min(it->second, (m-cnt*x) / (x+1)));
    auto remain = (it == mp.end() ? 0 : min(it->second-mx, cnt));
    auto got = cnt*x+mx*(x+1);
    res = max(res, got + min(remain, m-got));
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
