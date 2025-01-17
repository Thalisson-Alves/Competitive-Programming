#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, d;
  cin >> n >> d;
  string s;
  cin >> s;
  int cnt = 0;
  for (auto c : s) cnt += (c == '@');
  cout << n - (cnt - d) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
