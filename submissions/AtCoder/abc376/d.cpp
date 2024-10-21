#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u,--v;
    g[u].push_back(v);
  }

  vector<int> dist(n, INT_MAX);
  queue<int> q({0});
  dist[0] = 0;
  int res = m+10;
  while (q.size()) {
    auto u = q.front();
    q.pop();
    for (auto v : g[u]) {
      if (!v) res = min(res, dist[u]+1);
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  cout << (res>m?-1:res) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
