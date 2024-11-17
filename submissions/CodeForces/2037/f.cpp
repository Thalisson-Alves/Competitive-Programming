#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> h(n), p(n);
  for (auto &x : h) cin >> x;
  for (auto &x : p) cin >> x;
  auto f = [&](ll x) {
    vector<pair<ll, bool>> e;
    for (int i = 0; i < n; i++) {
      ll lst = p[i]+m-(h[i]+x-1)/x;
      ll fst = p[i]-m+(h[i]+x-1)/x;
      if (fst<=lst) e.emplace_back(fst, 0), e.emplace_back(lst, 1);
    }
    sort(begin(e), end(e));
    int tot = 0;
    for (auto [_, t] : e) {
      if (t) --tot;
      else if (++tot >= k) return true;
    }
    return false;
  };
  ll l = 1, r = INT_MAX;
  while (l <= r) {
    ll mid = midpoint(l, r);
    if (f(mid)) r = mid-1;
    else l = mid+1;
  }
  cout << (l >= INT_MAX ? -1 : l) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  while (t--) solve();
}
