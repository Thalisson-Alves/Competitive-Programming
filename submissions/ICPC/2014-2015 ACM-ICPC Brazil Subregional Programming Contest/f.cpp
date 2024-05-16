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
  vector<int> fat{1};
  for (int i = 2; fat.back() < n; i++)
    fat.push_back(i * fat.back());
  int res = 0;
  for (int i = (int)fat.size() - 1; ~i; --i) {
    auto [d, r] = div(n, fat[i]);
    res += d;
    n = r;
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
