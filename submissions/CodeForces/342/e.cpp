#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int dfs_size(const vector<vector<int>> &g, vector<int> &sz, vector<bool> &rem, int u, int p) {
  sz[u] = 1;
  for (auto x : g[u]) if (!rem[x] and x != p) {
    sz[u] += dfs_size(g, sz, rem, x, u);
  }
  return sz[u];
}

int centroid(const vector<vector<int>> &g, vector<int> &sz, vector<bool> &rem, int u, int p=-1) {
  const int max_sz = dfs_size(g, sz, rem, u, p) >> 1;
  for (;;) {
    bool ok = true;
    for (auto x : g[u]) if (!rem[x] and x != p) {
      if (sz[x] > max_sz) {
        p = u;
        u = x;
        ok = false;
        break;
      }
    }
    if (ok) break;
  }
  return u;
}

void dfs_dist(const vector<vector<int>> &g, vector<vector<pair<int, int>>> &ancestor, vector<bool> &rem, int c, int u, int p, int d=0) {
  ancestor[u].emplace_back(c, d);
  for (auto x : g[u]) if (!rem[x] and x != p) {
    dfs_dist(g, ancestor, rem, c, x, u, d+1);
  }
}

void centroid_decomposition(const vector<vector<int>> &g, vector<int> &sz, vector<vector<pair<int, int>>> &ancestor, vector<bool> &rem, int u=0) {
  const int c = centroid(g, sz, rem, u);
  rem[c] = true;
  dfs_dist(g, ancestor, rem, c, c, c);
  for (auto x : g[c]) if (!rem[x]) {
    centroid_decomposition(g, sz, ancestor, rem, x);
  }
}

// vector of pair of (parent centroid, distance)
vector<vector<pair<int, int>>> centroid_decomposition(const vector<vector<int>> &g) {
  vector<int> sz(g.size());
  vector<bool> rem(g.size());
  vector<vector<pair<int, int>>> ancestor(g.size());
  centroid_decomposition(g, sz, ancestor, rem);
  for (auto &x : ancestor) reverse(all(x));
  return ancestor;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
 
  auto ct = centroid_decomposition(g);
 
  vector<int> best(g.size(), INT_MAX);
  auto update = [&best, &ct](int u) -> void {
    best[u] = 0;
    for (auto [p, x] : ct[u]) {
      best[p] = min(best[p], best[u] + x);
    }
  };
 
  auto query = [&best, &ct](int u) -> int {
    for (auto [p, x] : ct[u]) {
      if (best[p] != INT_MAX)
        best[u] = min(best[u], best[p] + x);
    }
    return best[u];
  };
 
  update(0);
  while (q--) {
    int t, u;
    cin >> t >> u;
    --u;
    if (t == 1) {
      update(u);
    } else {
      cout << query(u) << '\n';
    }
  }
}

int32_t main()
{
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
