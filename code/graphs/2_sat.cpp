struct Sat2 {
  vector<vector<int>> g, gr;

  Sat2(int variables) : g(variables << 1), gr(variables << 1) {}

  void add_implication(int x, bool sign_x, int y, bool sign_y) {
    g[var(x, sign_x)].push_back(var(y, sign_y));
    gr[var(y, sign_y)].push_back(var(x, sign_x));
  }
  void add_xor(int x, bool sign_x, int y, bool sign_y) {
    add_or(x, sign_x, y, sign_y);
    add_or(x, not sign_x, y, not sign_y);
  }
  void add_and(int x, bool sign_x, int y, bool sign_y) {
    add_or(x, sign_x, x, sign_x);
    add_or(y, sign_y, y, sign_y);
  }
  void add_or(int x, bool sign_x, int y, bool sign_y) {
    add_implication(x, not sign_x, y, sign_y);
    add_implication(y, not sign_y, x, sign_x);
  }

  inline int var(int x, bool sign) const { return (x << 1) + sign; }
  inline int var_neg(int v) const { return v ^ 1; }
  inline bool var_sign(int v) const { return v & 1; }

  vector<bool> solve() {
    auto components = scc_components(g);
    vector<bool> ans(g.size() >> 1);
    for (int i = 0; i < (int)g.size(); i++) {
      int j = var_neg(i);
      auto ac = components[i];
      auto bc = components[j];
      if (ac == bc) return {};
      ans[i >> 1] = var_sign(ac > bc ? j : i);
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
