#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int a, b, k;
  cin >> a >> b >> k;
  auto x = string(b, '1') + string(a, '0');
  string y = x;
  swap(y[b-1], y[b-1+min(a, k)]);
  k -= min(a, k);
  for (int i = b-2; a and k and ~i; --i, --k) swap(y[i], y[i+1]);
  if (k or y[0]=='0') cout << "NO\n";
  else {
    cout << "YES\n";
    cout << x << '\n';
    cout << y << '\n';
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
