#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> pref(n+1), suf(n+1);
  vector<int> pos;
  for (int i = 0; i < n; i++) {
    pref[i+1] = pref[i] + (s[i] == '1');
    suf[n-i-1] = suf[n-i] + (s[n-i-1] == '2');
    if (s[i] == '/') pos.push_back(i);
  }
  auto f = [&](int l, int r, int x) { return 1 + 2 * min(pref[x]-pref[l], suf[x]-suf[r+1]); };
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    auto L = int(lower_bound(begin(pos), end(pos), l) - begin(pos));
    auto R = int(upper_bound(begin(pos), end(pos), r) - begin(pos)) - 1;
    int res = 0;
    while (L <= R) {
      auto m = midpoint(L, R);
      res = max(res, f(l, r, pos[m]));
      if (pref[pos[m]]-pref[l] > suf[pos[m]]-suf[r+1]) R = m-1;
      else L = m+1;
    }
    cout << res << '\n';
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
