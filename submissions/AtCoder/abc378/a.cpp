#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  map<int, int> mp;
  int res = 0;
  for (int i = 0; i < 4; i++) {
    int x;
    cin >> x;
    if (++mp[x]%2==0) res++;
  }
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
