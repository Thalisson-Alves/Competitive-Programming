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
  int cur = 0;
  for (auto c : s) {
    if (cur >= 3) break;
    if (c == tolower(t[cur])) cur++;
  }

  cout << (cur == 3 or (cur == 2 and t.back() == 'X') ? "Yes" : "No") << '\n';
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
