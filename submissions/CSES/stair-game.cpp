#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n; cin >> n;
  int res = 0;
  for (int i = 0, x; i < n and cin >> x; i++)
    if (i&1) res^=x;
  cout << (res ? "first" : "second") << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  while (t--) solve();
}
