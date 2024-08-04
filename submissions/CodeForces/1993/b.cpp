#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;
  int cnt[2] = {0, 0};
  for (auto x : v) cnt[x&1]++;
  if (cnt[0] == n or cnt[1] == n) {
    cout << "0\n";
    return;
  }
  ll mx_odd = 0;
  for (auto x : v) {
    if (x&1) mx_odd = max(mx_odd, x);
  }
  sort(v.begin(), v.end());
  ll res = 0;
  bool op = 0;
  for (int i = 0; i < n; i++) if (v[i]%2==0) {
    if (v[i] < mx_odd) {
      ++res;
      mx_odd += v[i];
    } else {
      ++res;
      op = 1;
    }
  }
  cout << res + op << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
