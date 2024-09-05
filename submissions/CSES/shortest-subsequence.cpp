#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  string s; cin >> s;
  vector<vector<int>> far(size(s) + 1, vector<int>(4, (int)size(s)));
  constexpr string_view dn = "ACGT";
  for (int i = (int)size(s)-1; ~i; --i) {
    auto id = dn.find(s[i]);
    far[i] = far[i+1];
    far[i][id] = i;
  }
  string res;
  for (int cur = -1; cur < (int)size(s);) {
    auto f = max_element(begin(far[cur+1]), end(far[cur+1]));
    res += dn[f-begin(far[cur+1])];
    cur = *f;
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
