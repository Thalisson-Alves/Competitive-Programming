#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &x : v) {
    string s;
    cin >> s;
    for (char c : s) x=(x<<1)|(c-'0');
  }
  int res = k+1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
       res = min(res, __builtin_popcount(v[i]^v[j]));
    }
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
