#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int a[5];
  for (auto &x : a) cin >> x;
  vector<pair<int, string>> res;
  for (int i = 0; i < 1<<5; ++i) {
    auto &[v, s] = res.emplace_back();
    for (int j = 0; j < 5; j++) {
      if (i>>j&1) {
        v += a[j];
        s += "ABCDE"[j];
      }
    }
  }
  sort(begin(res), end(res), [&](const auto &x, const auto &y) {
    return (x.first != y.first ? x.first > y.first : x.second < y.second);
  });
  for (auto &[_, s] : res) cout << s << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
