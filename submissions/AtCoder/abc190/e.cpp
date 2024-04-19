#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

template <typename Graph> auto bfs(const Graph &g, int s) {
  vector<int> dist(g.size(), numeric_limits<int>::max());
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (not q.empty()) {
    auto u = q.front(); q.pop();
    for (auto v : g[u]) {
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  return dist;
}

ll tsp(int i, int mask, const vector<vector<ll>> &dist, vector<vector<ll>> &memo) {
  if (mask == (1 << dist.size()) - 1)
    return 1;

  if (memo[i][mask] != -1)
    return memo[i][mask];

  ll ans = 1e18;
  for (int j = 0; j < (int)dist.size(); j++) {
    if (mask & (1 << j))
      continue;

    ans = min(ans, tsp(j, mask | (1 << j), dist, memo) + dist[i][j]);
  }

  return memo[i][mask] = ans;
}

ll tsp(int i, const vector<vector<ll>> &dist) {
  vector<vector<ll>> memo(dist.size(), vector<ll>(1ll << dist.size(), -1));
  return tsp(i, 1ll << i, dist, memo);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int k;
  cin >> k;
  vector<int> order(k);
  for (auto &x : order) cin >> x, --x;

  vector<vector<ll>> dists(k);
  for (int i = 0; i < k; i++) {
    vector<ll> norm(k);
    auto ds = bfs(g, order[i]);
    for (int j = 0, cur = 0; cur < k and j < n; j++) {
      if (j == order[cur]) {
        norm[cur++] = ds[j];
      }
    }
    dists[i] = norm;
  }

  ll res = INT_MAX;
  for (int i = 0; i < k; i++) {
    res = min(res, tsp(i, dists));
  }
  cout << (res >= INT_MAX ? -1 : res) << '\n';
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
