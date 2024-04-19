#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll n;
  cin >> n;
  int res = 0;
  for (ll i = 1; i*i <= n; i++) if (n % i == 0) {
    res += (i&1);
    res += (i*i != n and (n/i&1));
  }
  cout << res * 2 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
