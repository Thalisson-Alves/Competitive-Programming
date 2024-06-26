/* Strongly Connected Components
 *
 * Finds the strongly connected components of a directed graph, and builds the SCC tree.
 *
 * Fields:
 * - size: number of strongly connected components.
 * - comp_id: for each vertex, the id of the strongly connected component it belongs to.
 * - comps: for each strongly connected component, the list of vertices it contains.
 * - g: the SCC tree.
 *
 * Methods:
 * - SCC(g): builds the SCCs and the SCC tree.
 *   - O(n + m)
 * - minimum_augmentation: returns a list of edges to add to the graph to make it strongly connected.
 *   - O(n + m)
 *
 * Tested on:
 * - https://cses.fi/problemset/task/1685/
 */
template <typename Digraph> struct SCC {
  int size;
  vector<int> comp_id;
  vector<vector<int>> comps;
  Digraph g;

  SCC(const Digraph &g_) : size(0), comp_id(g_.size(), -1), g(0) {
    int timer = 1;
    vector<int> tin(g_.size()), st;
    st.reserve(g_.size());
    auto dfs = [&](auto&& self, int u) -> int {
      int low = tin[u] = timer++, now = (int)st.size();
      st.push_back(u);
      for (auto v : g_[u])
      if (comp_id[v] < 0)
        low = min(low, tin[v] ? tin[v] : self(self, v));
      if (tin[u] == low) {
        for (int i = now; i < (int)st.size(); i++)
          comp_id[st[i]] = size;
        st.resize(now);
        size++;
      }
      return low;
    };
    for (int i = 0; i < g_.size(); i++)
      if (!tin[i]) dfs(dfs, i);
    comps.resize(size);
    for (int i = 0; i < (int)comp_id.size(); i++) comps[comp_id[i]].push_back(i);

    g = [&]() {  // build scc tree
      set<pair<int, int>> edges;
      for (auto [u, v, _] : g_.edges) {
        if (comp_id[u] != comp_id[v])
          edges.emplace(comp_id[u], comp_id[v]);
      }
      auto tree = Digraph(size);
      for (auto [u, v] : edges)
        tree.add_edge(u, v);
      return tree;
    }();
  }

  vector<pair<int, int>> minimum_augmentation() const {
    if (g.size() <= 1) return {};

    vector<bool> zero_out(g.size(), 1), zero_in(g.size(), 1);
    for (int i = 0; i < (int)g.size(); i++) {
      zero_out[i] = g[i].empty();
      for (auto x : g[i])
      zero_in[x] = false;
    }

    vector<bool> vis(g.size());
    auto dfs = [&](auto &&self, int u) {
      vis[u] = 1;
      if (zero_out[u]) return u;
      for (auto v : g[u]) if (!vis[v]) {
        auto x = self(self, v);
        if (~x) return x;
      }
      return -1;
    };

    vector<int> sources, sinks;
    vector<int> unmatched_sources, unmatched_sinks;

    for (int i = 0; i < (int)g.size(); i++) if (zero_in[i]) {
      auto sink = dfs(dfs, i);
      if (~sink) {
        sources.push_back(i);
        sinks.push_back(sink);
      } else {
        unmatched_sources.push_back(i);
      }
    }

    for (int i = 0; i < (int)g.size(); i++) {
      if (zero_out[i] and !vis[i])
        unmatched_sinks.push_back(i);
    }

    int matches = (int)sources.size();
    sources.insert(sources.end(), unmatched_sources.begin(), unmatched_sources.end());
    sinks.insert(sinks.end(), unmatched_sinks.begin(), unmatched_sinks.end());
    int mn = (int)sources.size(), mx = (int)sinks.size();
    if (mn > mx) swap(mn, mx);

    vector<pair<int, int>> res;
    res.reserve(mx);

    res.emplace_back(0, matches - 1);
    for (int i = 1; i < matches; i++) res.emplace_back(i, i-1);
    for (int i = matches; i < mn; i++) res.emplace_back(i, i);
    for (int i = mn; i < (int)sources.size(); i++) res.emplace_back(0, i);
    for (int i = mn; i < (int)sinks.size(); i++) res.emplace_back(i, 0);
    for (auto &[a, b] : res) a = comps[sinks[a]][0], b = comps[sources[b]][0];
    return res;
  }
};
