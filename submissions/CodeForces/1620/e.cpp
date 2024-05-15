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
  vector<pair<int, int>> qs(n);
  for (auto &[a, b] : qs) {
    int t;
    cin >> t >> a;
    if (t == 2) cin >> b;
  }
  vector<int> res;
  vector<int> v(5e5+1);
  iota(v.begin(), v.end(), 0);
  for (int i = n-1; ~i; --i) {
    auto [a, b] = qs[i];
    if (b) {
      v[a] = v[b];
    } else {
      res.push_back(v[a]);
    }
  }
  for (int i = (int)res.size()-1; ~i; --i) {
    cout << res[i] << " \n"[i == 0];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
