template <typename Digraph> vector<int> scc_components(const Digraph &g) {
  static_assert(Digraph::is_directed());

  vector<int> comps(g.size(), -1);
  int timer = 1, num_sccs = 0;
  vector<int> tin(g.size()), st;
  st.reserve(g.size());
  auto dfs = [&](auto&& self, int u) -> int {
    int low = tin[u] = timer++, now = (int)st.size();
    st.push_back(u);
    for (auto [v, _] : g[u])
      if (comps[v] < 0)
        low = min(low, tin[v] ? tin[v] : self(self, v));
    if (tin[u] == low) {
      for (int i = now; i < (int)st.size(); i++)
        comps[st[i]] = num_sccs;
      st.resize(now);
      num_sccs++;
    }
    return low;
  };
  for (int i = 0; i < g.size(); i++)
    if (!tin[i]) dfs(dfs, i);

  return comps;
};
