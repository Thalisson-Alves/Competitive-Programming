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
  vector<pair<int, int>> v(n);
  for (auto &[a, b] : v) cin >> a >> b;
  sort(v.begin(), v.end());
  int res = 0;
  for (int i = 0; i < n; i++) {
    int mn = INT_MAX, mx = INT_MIN;
    for (int j = i+1; j < n; j++) {
      if (v[j].second > v[i].second) {
        res += v[j].second < mn;
        mn = min(mn, v[j].second);
      } else {
        res += v[j].second > mx;
        mx = max(mx, v[j].second);
      }
    }
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
