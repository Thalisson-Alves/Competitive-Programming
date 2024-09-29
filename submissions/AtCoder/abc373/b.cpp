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
  vector<int> pos(size(s));
  for (int i = 0; i < (int)s.size(); i++) {
    pos[s[i]-'A'] = i;
  }
  int res = 0;
  for (int i = 1; i < (int)pos.size(); i++) {
    res += abs(pos[i]-pos[i-1]);
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
