#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int x = min(a, b);
  cout << "0 0 " << x << ' ' << x << '\n';
  cout << x << " 0 0 " << x << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
