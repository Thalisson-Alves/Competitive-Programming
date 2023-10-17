bool bipartite_matching(const vector<vector<int>> &g, int u, vector<bool> &vis, vector<int> &matching) {
  if (vis[u]) return false;
  vis[u] = 1;
  for (auto v : g[u]) {
    if (matching[v] == -1 or bipartite_matching(g, v, vis, matching)) {
      matching[v] = u;
      return true;
    }
  }
  return false;
}

vector<int> bipartite_matching(const vector<vector<int>> &g) {
  vector<int> matching(g.size(), -1);
  vector<bool> vis(g.size());
  for (int i = 0; i < (int)g.size(); i++) {
    vis.assign(g.size(), 0);
    bipartite_matching(g, i, vis, matching);
  }
  return matching;
}
