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
  vector<int> p(n);
  for (auto &x : p) cin >> x, --x;
  vector<bool> vis(n);
  vector<vector<int>> cycles[2];
  for (int i = 0; i < n; i++) if (!vis[i]) {
    vector<int> c{i};
    for (int j = p[i]; j != c[0]; j = p[j])
      c.push_back(j), vis[j] = 1;
    swap(cycles[size(c)&1].emplace_back(), c);
  }
  sort(begin(cycles[0]), end(cycles[0]), [](const auto &a, const auto &b) { return size(a) < size(b); });
  bool can = ~size(cycles[0])&1;
  for (int i = 1; can and i < (int)size(cycles[0]); i+=2)
    can &= size(cycles[0][i]) == size(cycles[0][i-1]);
  if (!can) {
    cout << "-1\n";
    return;
  }
  vector<vector<int>> res_cycles;
  for (const auto &c : cycles[1]) {
    auto &v = res_cycles.emplace_back(size(c));
    for (int i = 0; i < (int)size(c); i++)
      v[2*i%size(c)] = c[i];
  }
  for (int i = 1; i < (int)size(cycles[0]); i+=2) {
    vector<int> c;
    for (int j = 0; j < (int)size(cycles[0][i]); j++) {
      c.push_back(cycles[0][i-1][j]);
      c.push_back(cycles[0][i][j]);
    }
    swap(res_cycles.emplace_back(), c);
  }
  vector<int> res(n);
  for (const auto &c : res_cycles) {
    for (int i = 0; i < (int)size(c); i++) {
      res[c[i]] = c[(i+1)%size(c)];
    }
  }
  for (int i = 0; i < n; i++) cout << res[i]+1 << " \n"[i == n-1];
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
