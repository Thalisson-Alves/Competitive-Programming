#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  sort(all(a));
  auto can = [&](ll x) -> bool {
    if (n / x < k) return false;
    vector<ll> v(x);
    vector<ll> cnt(x);
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < 2*v[cur])
        continue;
      v[cur] = a[i];
      if (cur == x - 1 and ++cnt[cur] == k) return true;
      cur = (cur + 1) % x;
    }
    return false;
  };
  ll l = 1, r = LLONG_MAX;
  while (l <= r) {
    auto m = midpoint(l, r);
    if (can(m)) l = m + 1;
    else r = m - 1;
  }
  cout << r << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}
