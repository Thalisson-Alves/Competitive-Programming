#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string o(n/2, '1');
  o += '/';
  o += string(n/2, '2');
  cout << (s == o ? "Yes": "No") << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
