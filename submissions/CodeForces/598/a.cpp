#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll n; cin >> n;
  ll sum = n*(n+1)/2;
  for (int i = 0; (1ll<<i)<=n; i++) {
    sum -= 2 *(1ll << i);
  }
  cout << sum << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
