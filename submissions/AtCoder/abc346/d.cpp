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
  string s;
  cin >> n >> s;
  vector<ll> cs(n);
  for (auto &x : cs)
    cin >> x;

  vector<ll> suf0(n), suf1(n);
  for (int i = n - 1; ~i; --i) {
    suf1[i] += (s[i] == '0') * cs[i];
    if (i + 2 < n)
      suf1[i] += suf1[i + 2];

    suf0[i] += (s[i] == '1') * cs[i];
    if (i + 2 < n)
      suf0[i] += suf0[i + 2];
  }

  vector<ll> pre0(n), pre1(n);
  for (int i = 0; i < n; i++) {
    pre1[i] += (s[i] == '0') * cs[i];
    if (i - 2 >= 0)
      pre1[i] += pre1[i - 2];

    pre0[i] += (s[i] == '1') * cs[i];
    if (i - 2 >= 0)
      pre0[i] += pre0[i - 2];
  }

  ll res = LLONG_MAX;
  for (int i = 1; i < n; i++) {
    // 00
    ll sum = suf0[i] + pre0[i - 1];
    if (i + 1 < n)
      sum += suf1[i + 1];
    if (i - 2 >= 0)
      sum += pre1[i - 2];
    res = min(res, sum);

    // 11
    sum = suf1[i] + pre1[i - 1];
    if (i + 1 < n)
      sum += suf0[i + 1];
    if (i - 2 >= 0)
      sum += pre0[i - 2];
    res = min(res, sum);
  }

  cout << res << '\n';
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
