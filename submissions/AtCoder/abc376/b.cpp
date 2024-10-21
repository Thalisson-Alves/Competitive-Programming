#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;
  int l = 0, r = 1;
  int res = 0;
  while (q--) {
    char c; int t;
    cin >> c >> t;
    --t;
    if (c == 'L') {
      if (t <= l) {
        if (r < t or r > l) res += l-t;
        else res += n-l+t;
      } else {
        if (r > t or r < l) res += t-l;
        else res += l+n-t;
      }
      l = t;
    } else {
      if (t <= r) {
        if (l < t or l > r) res += r-t;
        else res += n-r+t;
      } else {
        if (l > t or l < r) res += t-r;
        else res += r+n-t;
      }
      r = t;
    }
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
