#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  unordered_map<int, int> last(n);
  int prev_l = 0;
  constexpr auto sum = [](ll sz) { return sz*(sz+1)/2; };
  ll res = 0;
  for (int l = 0, r = 0; r < n; r++) {
    auto &lst = last[v[r]];
    l = max(l, lst);
    lst = r+1;
    if (l != prev_l) {
      res += sum(r-prev_l) - sum(r-l);
      prev_l = l;
    }
  };
  res += sum(n-prev_l);
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
