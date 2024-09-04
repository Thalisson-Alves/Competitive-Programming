#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int a, b, m;
  cin >> a >> b >> m;
  vector<pair<int, int>> es(m);
  vector<int> t(a+b);
  for (auto &[u, v] : es) {
    cin >> u >> v;
    --u, --v;
    v += a;
    t[u]++, t[v]++;
  }
  int mx = *max_element(begin(t), end(t));
  cout << mx << '\n';
  vector<vector<int>> res(a+b, vector<int>(mx, -1));
  for (auto [u, v] : es) {
    int c1 = 0, c2 = 0;
    while (~res[u][c1]) c1++;
    while (~res[v][c2]) c2++;
    res[u][c1] = v;
    for (int i = v, c = c2; c1!=c2 and ~i; i = res[i][c], c^=c1^c2)
      swap(res[i][c1], res[i][c2]);
    res[v][c1] = u;
  }
  for (auto [u, v] : es) {
    for (int i = 0; i < mx; i++)
      if (res[u][i] == v) {
        cout << i+1 << ' ';
        break;
      }
  }
  cout << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
