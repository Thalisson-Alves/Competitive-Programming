/* 2-SAT
 *
 * Given a boolean formula in 2-CNF, determine if it is satisfiable.
 * A 2-CNF formula is a conjunction of disjunctions of two literals.
 *
 * To negate a variable, use ~x.
 *
 * Time complexity: O(V+E)
 */
struct Sat2 {
  vector<vector<int>> g;
  Sat2(int variables) : g(variables << 1) {}
  void add_implication(int x, int y) {
    x = max(~x<<1^1, x<<1);
    y = max(~y<<1^1, y<<1);
    g[x].push_back(y);
  }
  void add_xor(int x, int y) {
    add_or(x, y);
    add_or(~x, ~y);
  }
  void add_and(int x, int y) {
    add_or(x, x);
    add_or(y, y);
  }
  void add_or(int x, int y) {
    add_implication(~x, y);
    add_implication(~y, x);
  }
  vector<bool> solve() {
    auto components = scc_components(g);
    vector<bool> ans(g.size() >> 1);
    for (int i = 0; i < (int)g.size(); i+=2) {
      auto ac = components[i];
      auto bc = components[i^1];
      if (ac == bc) return {};
      ans[i>>1] = ac < bc;
    }
    return ans;
  }
private:
  static vector<int> scc_components(const vector<vector<int>> &g) {
    vector<int> comps(g.size(), -1);
    int timer = 1, num_sccs = 0;
    vector<int> tin(g.size()), st;
    st.reserve(g.size());
    auto dfs = [&](auto&& self, int u) -> int {
      int low = tin[u] = timer++, now = (int)st.size();
      st.push_back(u);
      for (auto v : g[u])
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
    for (int i = 0; i < (int)g.size(); i++)
      if (!tin[i]) dfs(dfs, i);
    return comps;
  };
};
