struct VirtualTree {
  LCA lca;
  vector<vector<pair<int, int>>> tree;
  VirtualTree(const vector<vector<int>> &g, int root=0) : lca(g, root), tree(size(g)) {}
  int build(vector<int> v) {
    auto cmp = [&](int i, int j) { return lca.pos[i] < lca.pos[j]; };
    sort(begin(v), end(v), cmp);
    for (int i = (int)size(v)-1; i; --i) v.push_back(lca.lca(v[i], v[i-1]));
    sort(begin(v), end(v), cmp);
    v.erase(unique(begin(v), end(v)), end(v));
    for (int i = 0; i < (int)size(v); i++) tree[i].clear();
    for (int i = 1; i < (int)size(v); i++) tree[lca.lca(v[i-1], v[i])].clear();
    for (int i = 1; i < (int)size(v); i++) {
      int p = lca.lca(v[i-1], v[i]);
      tree[p].emplace_back(v[i], lca.dist(p, v[i]));
    }
    return v[0];
  }
};
