#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    g[--x].push_back(i);
  }
  vector<int> w(n);
  for (auto &x : w) cin >> x;

  vector<int> lis, res(n);
  auto dfs = [&](auto &&self, int u) -> void {
    int it = int(lower_bound(all(lis), w[u]) - lis.begin());
    int prev = -1;
    if (it < (int)lis.size()) {
      prev = lis[it];
      lis[it] = w[u];
    } else {
      lis.push_back(w[u]);
    }

    res[u] = (int)lis.size();

    for (auto v : g[u])
      self(self, v);

    if (~prev) {
      lis[it] = prev;
    } else {
      lis.pop_back();
    }
  };

  dfs(dfs, 0);
  for (int i = 1; i < n; i++)
    cout << res[i] << " \n"[i == n-1];
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
