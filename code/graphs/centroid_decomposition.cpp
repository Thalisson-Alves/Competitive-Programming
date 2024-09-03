void centroid_decomposition(const vector<vector<int>> &g, auto &&f) {
  vector<int> sz(g.size());
  vector<bool> rem(g.size());
  auto dfs_size = [&](auto &&self, int u, int p=-1) -> int {
    sz[u] = 1;
    for (auto v : g[u]) if (v != p and !rem[v])
      sz[u] += self(self, v, u);
    return sz[u];
  };
  auto centroid = [&](auto &&self, int u, int p, int tsize) -> int {
    for (auto v : g[u])
      if (v != p and !rem[v] and sz[v] >= tsize)
        return self(self, v, u, tsize);
    return u;
  };
  auto dfs = [&](auto &&self, int u) -> void {
    const int c = centroid(centroid, u, -1, dfs_size(dfs_size, u) >> 1);
    rem[c] = 1;
    f(c, rem);
    for (auto v : g[c]) if (!rem[v]) self(self, v);
  };
  dfs(dfs, 0);
}
// vector of pair of (parent centroid, distance)
vector<vector<pair<int, int>>>  centroid_decomposition(const vector<vector<int>> &g) {
  vector<vector<pair<int, int>>> ancestor(g.size());
  auto run = [&](int cent, const auto &rem) {
    auto dfs_dist = [&](auto &&self, int c, int u, int p, int d) -> void {
      ancestor[u].emplace_back(c, d);
      for (auto v : g[u]) if (v != p and !rem[v]) self(self, c, v, u, d+1);
    };
    dfs_dist(dfs_dist, cent, cent, -1, 0);
  };
  centroid_decomposition(g, run);
  for (auto &x : ancestor) reverse(begin(x), end(x));
  return ancestor;
}
