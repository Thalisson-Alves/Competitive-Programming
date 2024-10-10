#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  auto calc_pref = [&]() {
    stack<pair<ll, int>> st;
    ll total = 0;
    vector<ll> pref(n);
    for (int i = 0; i < n; i++) {
      pair<ll, int> cur = {a[i], 1};
      while (size(st) and st.top().first > cur.first) {
        total -= st.top().first * st.top().second;
        cur.second += st.top().second;
        st.pop();
      }
      st.push(cur);
      total += cur.first * cur.second;
      pref[i] = total;
    }
    return pref;
  };
  auto pref = calc_pref();
  reverse(begin(a), end(a));
  auto suf = calc_pref();
  reverse(begin(a), end(a));
  reverse(begin(suf), end(suf));
  int idx = 0;
  for (int i = 1; i < n; i++) {
    if (pref[i]+suf[i]-a[i] > pref[idx]+suf[idx]-a[idx])
      idx = i;
  }
  vector<int> res(n);
  res[idx] = a[idx];
  for (int i = idx-1, mx = a[idx]; ~i; --i)
    res[i] = mx = min(mx, a[i]);
  for (int i = idx+1, mx = a[idx]; i < n; ++i)
    res[i] = mx = min(mx, a[i]);
  for (int i = 0; i < n; i++) cout << res[i] << " \n"[i==n-1];
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
