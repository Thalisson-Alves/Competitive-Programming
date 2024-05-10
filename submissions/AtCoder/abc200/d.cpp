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
  vector<int> a(n = min(n, 8));
  for (auto &x : a)
    cin >> x, x %= 200;

  vector<vector<int>> memo(200);
  for (int i = 0; i < (1 << n); i++) {
    vector<int> s;
    int sum = 0;
    for (int j = 0; j < n; j++) if (i >> j & 1) {
      s.push_back(j);
      (sum += a[j]) %= 200;
    }
    if (memo[sum].size()) {
      cout << "Yes\n";
      cout << s.size();
      for (auto x : s) cout << ' ' << x + 1;
      cout << '\n' << memo[sum].size();
      for (auto x : memo[sum]) cout << ' ' << x + 1;
      cout << '\n';
      return;
    }
    else memo[sum] = s;
  }
  cout << "No\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
