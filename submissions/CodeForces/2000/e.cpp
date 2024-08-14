#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m, k, w;
  cin >> n >> m >> k >> w;
  vector<int> a(w);
  for (auto &x : a) cin >> x;
  vector<int> cnt(k*k+1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      auto times = 1ll*min({i+1, n-i, k, n-k+1})*min({k, j+1, m-j, m-k+1});
      cnt[times]++;
    }
  }
  sort(rbegin(a), rend(a));
  ll res = 0;
  for (int i = 0, times = k*k; i < w; i++) {
    while (!cnt[times]) times--;
    cnt[times]--;
    res += 1ll * a[i] * times;
  }
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
