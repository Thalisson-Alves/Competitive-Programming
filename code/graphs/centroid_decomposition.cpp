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
  for (auto &x : ancestor) reverse(x.begin(), x.end());
  return ancestor;
}
