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
  cin >> n;
  vector<int> v(n), rev(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i], --v[i];
    rev[v[i]] = i;
  }

  vector<pair<int, int>> res;
  for (int i = 0; i < n; i++) {
    if (i == rev[i]) continue;
    res.emplace_back(i, rev[i]);
    swap(rev[i], rev[v[i]]);
    swap(v[i], v[rev[v[i]]]);
  }

  cout << res.size() << '\n';
  for (auto [a, b] : res) cout << a+1 << ' ' << b+1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
