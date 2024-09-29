#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m; ll k;
  cin >> n >> m >> k;
  vector<pair<ll, int>> a(n);
  ll rem = k;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first; a[i].second = i;
    rem -= a[i].first;
  }
  if (n == m) {
    for (int i = 0; i < n; i++)
      cout << 0 << " \n"[i == n-1];
    return;
  }
  sort(begin(a), end(a));
  vector<ll> pref(n+1);
  for (int i = 0; i < n; i++)
    pref[i+1] = pref[i] + a[i].first;
  vector<ll> res(n);
  for (int i = 0; i < n; i++) {
    auto can = [&](ll x) {
      auto lst = upper_bound(begin(a), end(a), make_pair(a[i].first + x, n)) - begin(a);
      auto fst = n-m-(i>=n-m);
      if (lst < fst) return false;
      ll cost = (a[i].first+x+1) * (lst-fst) - (pref[lst] - pref[fst]);
      if (i>=n-m) cost -= x+1;
      return cost > (rem-x);
    };
    ll l = 0, r = rem;
    while (l <= r) {
      auto mid = midpoint(l, r);
      if (can(mid)) r = mid - 1;
      else l = mid + 1;
    }
    res[a[i].second] = l > rem ? -1 : l;
  }
  for (auto x : res) cout << x << ' ';
  cout << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
