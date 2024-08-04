#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  int mx = 0;
  for (auto &x : v) cin >> x, mx = max(mx, x), x %= 2*k;
  sort(v.begin(), v.end());
  int l = v[0], r = v[0]+k;
  for (auto x : v) {
    if (r < x) {
      l += 2*k;
      r += 2*k;
    }

    l = max(l, x);
    r = min(r, x+k);
  }
  if (r <= l) {
    cout << "-1\n";
    return;
  } else {
    cout << mx + (l-mx%k+k) % k << '\n';
  }
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
