#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  string s;
  cin >> s;
  bool res = true;
  for (int i = 0; res and i < (int)s.size(); i++) {
    if (i&1) {
      res &= 'A' <= s[i] and s[i] <= 'Z';
    } else {
      res &= 'a' <= s[i] and s[i] <= 'z';
    }
  }
  cout << (res ? "Yes" : "No") << '\n';
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
