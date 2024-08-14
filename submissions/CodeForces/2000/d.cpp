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
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  string s; cin >> s;
  vector<int> pl(n+1), pr(n+1);
  for (int i = 0; i < n; i++) {
    pl[i+1] = pl[i] + (s[i] == 'L');
    pr[n-i-1] = pr[n-i] + (s[n-i-1] == 'R');
  }
  ll res = 0;
  for (int i = 0; i < n; i++)
    res += a[i] * min(pl[i+1], pr[i]);
  cout << res << '\n';
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
