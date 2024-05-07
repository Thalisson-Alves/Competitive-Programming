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
  vector<int> res;
  int last = 0;
  cin >> last;
  for (int x; cin >> x;) {
    if (x == 1) res.push_back(last);
    last = x;
  }
  res.push_back(last);
  cout << res.size() << '\n';
  for (auto x : res) cout << x << ' ';
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
