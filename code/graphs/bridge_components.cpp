template <typename T> vector<int> bridge_components(const Undigraph<T> &g) {
  vector<int> tin(g.size()), tout(g.size()), low(g.size()), res(g.size());
  stack<int> st;
  int timer = 0, comp_id = 0;

  auto dfs = [&](auto &&self, int u, int p) -> void {
    tin[u] = low[u] = timer++;
    st.push(u);

    for (auto [v, _] : g[u]) if (v != p) {
      if (tin[v]) {
        low[u] = min(low[u], tin[v]);
      } else {
        self(self, v, u);
        low[u] = min(low[u], low[v]);
      }
    }

    if (tin[u] == low[u]) {
      ++comp_id;
      int v;
      do {
        v = st.top();
        st.pop();
        res[v] = comp_id;
      } while (v != u);
    }
  };

  for (int i = 0; i < g.size(); i++) {
    if (!tin[i])
      dfs(dfs, i, -1);
  }

  return res;
}
