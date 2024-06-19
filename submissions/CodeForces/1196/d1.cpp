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
  string s;
  cin >> s;
  int res = INT_MAX;
  for (int j = 0; j < 3; j++) {
    vector<int> pref(n+1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + (s[i] != "RGB"[(j+i)%3]);
      if (i+1 >= k) res = min(res, pref[i+1] - pref[i-k+1]);
    }
  }
  cout << res << '\n';
}

// clang-format off
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
