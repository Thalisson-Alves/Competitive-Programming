#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int k;
  cin >> k;
  vector<int> a(k);
  for (auto &x : a) cin >> x;
  sort(begin(a), end(a));
  int tot = k-2;
  for (int n = 1; n <= tot; n++) if (tot%n==0) {
    if (binary_search(begin(a), end(a), n) and binary_search(begin(a), end(a), tot/n)) {
      cout << n << ' ' << tot/n << '\n';
      return;
    }
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  while (t--) solve();
}
