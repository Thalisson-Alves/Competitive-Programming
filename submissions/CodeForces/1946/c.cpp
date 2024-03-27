#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> sz(n);
  auto dfs = [&](auto &&self, int u, int p, int x, int &remain) -> int {
    sz[u] = 1;
    int res = 0;
    for (auto v : g[u]) if (v != p) {
      res += self(self, v, u, x, remain);
      if (sz[v] >= x and remain - sz[v] >= x) {
        ++res;
        remain -= sz[v];
      }
      else sz[u] += sz[v];
    }
    return res;
  };

  int l = 1, r = n;
  while (l <= r) {
    int mid = midpoint(l, r);
    int rem = n;
    if (dfs(dfs, 0, -1, mid, rem) >= k) l = mid + 1;
    else r = mid - 1;
  }
  cout << r << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}
