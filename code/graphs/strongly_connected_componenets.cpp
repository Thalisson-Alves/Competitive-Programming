vector<int> topological_order(const vector<vector<int>> &g) {
  vector<char> vis(g.size());
  vector<int> order;
  order.reserve(g.size());
  auto dfs = [&](auto &&self, int u) -> void {
    vis[u] = true;
    for (auto v : g[u])
      if (not vis[v])
        self(self, v);
    order.push_back(u);
  };

  for (auto i = 0; i < (int)g.size(); i++)
    if (not vis[i])
      dfs(dfs, i);

  reverse(order.begin(), order.end());
  return order;
}

vector<int> mark_components(const vector<vector<int>> &gr, const vector<int> &order) {
  vector<int> comps(gr.size(), -1);
  auto dfs = [&](auto &&self, int u) -> void {
    for (auto x : gr[u]) {
      if (comps[x] == -1) {
        comps[x] = comps[u];
        self(self, x);
      }
    }
  };

  int id = 0;
  for (auto u : order) {
    if (comps[u] == -1) {
      comps[u] = id++;
      dfs(dfs, u);
    }
  }
  return comps;
}

vector<set<int>> components_tree(const vector<vector<int>> &g, const vector<int> &components) {
  int n = (int)g.size();
  vector<set<int>> tree(*max_element(all(components))+1);
  for (int i = 0; i < n; i++) {
    for (auto x : g[i])
      if (components[i] != components[x])
        tree[components[i]].insert(components[x]);
  }
  return tree;
}

vector<set<int>> components_tree(const vector<vector<int>> &g, const vector<vector<int>> &gr) {
  return components_tree(g, mark_components(gr, topological_order(g)));
}
