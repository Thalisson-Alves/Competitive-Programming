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
  int q; cin >> q;
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    auto first = rbegin(s)+(size(s)-r);
    auto mid = first+k%(r-l+1);
    auto last = rbegin(s)+(size(s)-l+1);
    rotate(first, mid, last);
  }
  cout << s << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
