#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll n; int k;
  cin >> n >> k;
  vector<ll> a(k);
  for (auto &x : a) cin >> x;
  ll res = 0;
  for (int i = 1; i < 1 << k; i++) {
    ll num = 1;
    int cnt = 0;
    for (int j = 0; j < k; j++) {
      if (i>>j&1) {
        if (num > n / a[j]) {
          num = -1;
          break;
        }
        num *= a[j];
        cnt++;
      }
    }
    if (num == -1) continue;
    if (cnt&1) res += n/num;
    else res -= n/num;
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
