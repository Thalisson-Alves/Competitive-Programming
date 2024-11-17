#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<int> pmx(n), smx(n);
  for (int i = 0; i < n; i++) {
    pmx[i] = max(i ? pmx[i-1] : 0, a[i]+i);
    smx[n-i-1] = max(i ? smx[n-i] : INT_MIN, a[n-i-1]-(n-i-1));
  }
  ll res = 0;
  for (int i = 1; i < n-1; i++) {
    res = max(res, (ll)a[i]+pmx[i-1]+smx[i+1]);
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  while (t--) solve();
}
