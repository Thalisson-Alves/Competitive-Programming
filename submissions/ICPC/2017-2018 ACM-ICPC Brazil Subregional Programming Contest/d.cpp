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
  int factors = 0;
  for (ll i = 2; i * i <= n; i++) {
    int cnt = 0;
    for (; n % i == 0; n /= i, ++cnt);
    factors += cnt > 0;
  }
  factors += n > 1;
  cout << (1 << factors) - factors - 1 << '\n';
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
