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
  sort(a.begin(), a.end());
  vector<ll> pref(n+1);
  partial_sum(a.begin(), a.end(), pref.begin()+1);
  constexpr ll mod = 1e8;
  ll res = 0;
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(a.begin()+i, a.end(), mod-a[i]) - a.begin();
    if (it > i)
      res += (it - i - 1) * a[i] + pref[it] - pref[i+1];
    else
      it++;

    if (it < n)
      res += (n - it) * a[i] + (pref[n] - pref[it]) - (n - it) * mod;
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
