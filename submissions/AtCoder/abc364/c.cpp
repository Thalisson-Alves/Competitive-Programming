#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n; ll cx, cy;
  cin >> n >> cx >> cy;
  vector<ll> sw(n), sa(n);
  for (auto &x : sw) cin >> x;
  for (auto &x : sa) cin >> x;
  sort(sw.rbegin(), sw.rend());
  sort(sa.rbegin(), sa.rend());
  ll sum = 0, cnt = 0;
  for (auto x : sw) {
    ++cnt;
    if ((sum += x) > cx)
      break;
  }
  auto res = cnt;
  sum = 0, cnt = 0;
  for (auto x : sa) {
    ++cnt;
    if ((sum += x) > cy)
      break;
  }
  cout << min(res, cnt) << '\n';
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

