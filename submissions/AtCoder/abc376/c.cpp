#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n-1);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  sort(rbegin(a), rend(a));
  sort(rbegin(b), rend(b));
  int pos = n;
  for (int i = 0; auto x : b) {
    if (a[i++] > x) {
      pos = i;
      break;
    }
  }
  for (int i = pos; i < n; i++) {
    if (a[i] > b[i-1]) {
      cout << "-1\n";
      return;
    }
  }
  cout << a[pos-1] << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
