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
  auto f = [&](int k) {
    vector<int> hist(20);
    int val = 0, prev = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 20; j++) {
        if ((a[i] >> j & 1) and ++hist[j] == 1)
          val ^= 1 << j;
      }
      if (i == k-1) prev = val;
      if (i < k) continue;
      for (int j = 0; j < 20; j++) {
        if ((a[i-k] >> j & 1) and --hist[j] == 0)
          val ^= 1 << j;
      }
      if (val != prev) return false;
    }
    return true;
  };

  int l = 1, r = n;
  while (l <= r) {
    auto m = midpoint(l, r);
    if (f(m)) r = m - 1;
    else l = m + 1;
  }
  cout << l << '\n';
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
