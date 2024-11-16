#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int q;
  cin >> q;
  while (q--) {
    ll k;
    cin >> k;
    --k;
    ll sz = (int)s.size();
    while (sz <= k) sz <<= 1;
    bool flip = 0;
    while (k >= (int)s.size()) {
      ll mid = (sz>>=1);
      if (k >= mid) {
        k -= mid;
        flip^=1;
      }
    }
    if (flip) {
      if (islower(s[k])) cout << char(toupper(s[k]));
      else cout << char(tolower(s[k]));
    } else {
      cout << s[k];
    }
    cout << " \n"[!q];
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
