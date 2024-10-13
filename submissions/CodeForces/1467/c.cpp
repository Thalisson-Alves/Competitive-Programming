#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int sz[3];
  cin >> sz[0] >> sz[1] >> sz[2];
  vector<int> mn(3, INT_MAX);
  vector<ll> sum(3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0, x; j < sz[i]; j++) cin >> x, sum[i] += x, mn[i] = min(mn[i], x);
  }
  ll res = sum[0]+max({sum[1]-2*mn[2]+sum[2]-2*mn[1], sum[1]-sum[2], sum[2]-sum[1]});
  res = max(res, sum[1]+max({sum[0]-2*mn[2]+sum[2]-2*mn[0], sum[0]-sum[2], sum[2]-sum[0]}));
  res = max(res, sum[2]+max({sum[1]-2*mn[0]+sum[0]-2*mn[1], sum[1]-sum[0], sum[0]-sum[1]}));
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
