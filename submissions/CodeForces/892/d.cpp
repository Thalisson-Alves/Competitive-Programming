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
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  auto sv = v;
  sort(sv.begin(), sv.end());
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[sv[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    cout << sv[(mp[v[i]] - 1 + n) % n] << " \n"[i == n-1];
  }
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
