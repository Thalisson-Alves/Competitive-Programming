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
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<bool> is_rec(n);
  for (int mx = -1, i = 0; i < n; i++) {
    is_rec[i] = a[i] > mx;
    mx = max(mx, a[i]);
  }
  int res = n, best = -1;
  for (int i = 0; i < n; i++) if (!is_rec[i]) {
    res = min(res, a[i]);
    best = 1;
  }
  for (int i = 0, mx = -1; i < n; i++) if (is_rec[i]) {
    int cnt = 0;
    for (int j = i+1, mx2 = mx; j < n and !is_rec[j]; j++) {
      cnt += a[j] > mx2;
      mx2 = max(mx2, a[j]);
    }
    if (cnt > best or (cnt == best and a[i] < res)) {
      res = a[i];
      best = cnt;
    }
    mx = a[i];
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
