#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<bool> covered(m);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    for (--l; l < r; l++)
      covered[l] = 1;
  }

  vector<int> res;
  for (int i = 0; i < m; i++) {
    if (!covered[i])
      res.push_back(i);
  }

  cout << res.size() << '\n';
  for (int i = 0; i < (int)res.size(); i++)
    cout << res[i] + 1 << " \n"[i == (int)res.size() - 1];
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
