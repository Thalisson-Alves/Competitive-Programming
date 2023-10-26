struct CentroidTree {
  // distance from i to kth ancestor, dist[i][0] = 0
  vector<vector<int>> dist;
  // parent of i in centroid tree
  vector<int> ps;

  CentroidTree(const vector<vector<int>> &g) : dist(g.size()), ps(g.size()), g_(g), sz(g.size()), rem(g.size()) {
    decomp(0);
    for (auto &x : dist) reverse(all(x));
  }

private:
  const vector<vector<int>> &g_;
  vector<int> sz;
  vector<bool> rem;

  int centroid(int u, int p, int hs) const {
    for (auto x : g_[u]) if (not rem[x] and x != p and sz[x] > hs) return centroid(x, u, hs);
    return u;
  }

  int dfs_size(int u, int p=-1) {
    sz[u] = 1;
    for (auto x : g_[u]) if (not rem[x] and x != p) sz[u] += dfs_size(x, u);
    return sz[u];
  }

  void dfs_dist(int u, int p, int d=0) {
    dist[u].push_back(d);
    for (auto x : g_[u]) if (not rem[x] and x != p) dfs_dist(x, u, d+1);
  }

  void decomp(int u, int p=-1) {
    int c = centroid(u, -1, dfs_size(u)/2);
    rem[c] = 1;
    ps[c] = p;
    dfs_dist(c, -1);
    for (auto x : g_[c]) if (not rem[x]) decomp(x, c);
  }
};
