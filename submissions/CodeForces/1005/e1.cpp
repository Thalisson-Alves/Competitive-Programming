#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  bool found = 0;
  int sum = 0;
  ll res = 0;
  map<int, int> mp;
  mp[0] = 1;
  for (int x; cin >> x;) {
    x = clamp(x-m, -1, 1);
    sum += x;
    found |= x == 0;
    if (found) res += mp[sum] + mp[sum - 1];
    else mp[sum]++;
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
