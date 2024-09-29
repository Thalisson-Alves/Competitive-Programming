#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  constexpr int n = 8;
  vector<string> v(n);
  for (auto &s : v) cin >> s;
  vector<int> o(n);
  iota(begin(o), end(o), 0);
  ll res = 0;
  do {
    bool ok = 1;
    for (int i = 0; ok and i < n; i++) {
      ok &= v[i][o[i]] == '.';
      for (int j = min(i,o[i]); ok and max(i,o[i])-j < n; --j)
        ok &= !j or o[i-j] != o[i]-j;
      for (int j = min(i,n-o[i]-1); ok and max(i,n-1-o[i])-j < n; --j)
        ok &= !j or o[i-j] != o[i]+j;
    }
    res += ok;
  } while (next_permutation(begin(o), end(o)));
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
