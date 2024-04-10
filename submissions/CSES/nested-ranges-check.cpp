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
  vector<array<int, 3>> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i][0] >> v[i][1], v[i][2] = i;

  sort(v.begin(), v.end(), [&](const auto &a, const auto &b) {
    return make_pair(a[0], -a[1]) < make_pair(b[0], -b[1]);
  });

  vector<bool> contain(n), contained(n);
  int mx = 0, mn = INT_MAX;
  for (int i = 0; i < n; i++) {
    {
      const auto &[_, r, id] = v[i];
      if (mx >= r) contained[id] = 1;
      mx = max(mx, r);
    }
    {
      const auto &[_, r, id] = v[n-i-1];
      if (mn <= r) contain[id] = 1;
      mn = min(mn, r);
    }
  }

  for (int i = 0; i < n; i++) cout << contain[i] << " \n"[i == n-1];
  for (int i = 0; i < n; i++) cout << contained[i] << " \n"[i == n-1];
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
