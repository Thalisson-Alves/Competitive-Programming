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
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  unordered_map<int, int> mp;
  ll res = 0;
  for (int l = 0, r = 0; r < n; r++) {
    ++mp[a[r]];
    for (; (int)mp.size() > k; l++)
      if (!--mp[a[l]])
        mp.erase(a[l]);
    res += r - l + 1;
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
