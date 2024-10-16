#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x, --x;
  vector<int> hist(n*n);
  ll res = 0;
  for (int j = n-1; ~j; --j) {
    for (int i = 0; i < j; i++) res += hist[a[i]*n+a[j]];
    for (int i = j+1; i < n; i++) hist[a[j]*n+a[i]]++;
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
