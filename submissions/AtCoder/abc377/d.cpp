#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> rs(m);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    --r;
    rs[r] = max(rs[r], l);
  }
  for (int i = 1; i < m; i++) rs[i] = max(rs[i], rs[i-1]);
  ll res = 0;
  for (int i = 0; i < m; i++) res += i-rs[i]+1;
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
