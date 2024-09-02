#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

ll josephus(ll n, ll k) {
  if (n == 1) return 1;
  if (k <= (n+1)/2) return (2*k > n ? 2*k%n : 2*k);
  auto x = josephus(n>>1,k-(n+1)/2);
  return 2*(x+(n&1))-1;
}

void solve() {
  int n, k;
  cin >> n >> k;
  cout << josephus(n, k) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
