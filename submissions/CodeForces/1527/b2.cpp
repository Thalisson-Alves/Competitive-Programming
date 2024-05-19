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
  string s;
  cin >> n >> s;
  bool is_pal = 1;
  for (int i = 0; is_pal and i < n/2; i++) {
    is_pal &= (s[i] == s[n-i-1]);
  }
  int cnt = (int)count(s.begin(), s.end(), '0');
  if (is_pal) {
    cout << ((cnt&1) and cnt > 1 ? "ALICE" : "BOB") << '\n';
  } else {
    cout << (cnt==2 and (n&1) and s[n>>1] == '0' ? "DRAW" : "ALICE") << '\n';
  }
}

// clang-format off
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
