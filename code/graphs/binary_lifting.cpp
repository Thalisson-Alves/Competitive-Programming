struct BinaryLifting {
  vector<int> far, depth, parent;
  BinaryLifting(const vector<vector<int>> &g, int root=0) : far(size(g), -1), depth(size(g)), parent(size(g), -1) {
    vector<int> q{root};
    q.reserve(size(g));
    for (int i = 0; i < (int)q.size(); i++) {
      auto u = q[i];
      for (auto v : g[u]) if (v != parent[u]) {
        parent[v] = u;
        depth[v] = depth[u] + 1;
        int p1 = u;
        int p2 = far[u];
        if (~p2 and ~far[p2] and depth[p1] - depth[p2] == depth[p2] - depth[far[p2]]) far[v] = far[p2];
        else far[v] = p1;
        q.push_back(v);
      }
    }
  }
  int kth_parent(int u, int k) const {
    while (~u and k > 0) {
      if (~far[u] and depth[u] - k < depth[far[u]]) {
        k -= depth[u] - depth[far[u]];
        u = far[u];
      } else {
        k--;
        u = parent[u];
      }
    }
    return u;
  }
  int lca(int u, int v) const {
    if (depth[u] < depth[v]) swap(u, v);
    while (depth[v] < depth[u]) {
      if (~far[u] and depth[v] <= depth[far[u]]) u = far[u];
      else u = parent[u];
    }
    if (u == v) return u;
    while (parent[u] != parent[v]) {
      if (~far[u] and ~far[v] and far[u] != far[v])
        u = far[u], v = far[v];
      else
        u = parent[u], v = parent[v];
    }
    return parent[u];
  }
};
