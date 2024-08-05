#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  string s, t;
  cin >> s >> t;

  auto k = s[0] - t[0];
  for (int i = 0; i < (int)s.size(); i++) {
    if ((((t[i] - 'a' + k) % 26 + 26) % 26 + 'a') != s[i]) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
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
