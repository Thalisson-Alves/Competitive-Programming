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
    auto order = topological_order(g);
    auto components = mark_components(gr, order);
    vector<int> comp_order(components.size(), (int)g.size());
    vector<bool> ans(g.size() >> 1);
    for (int i = 0; i < (int)g.size(); i++) {
      auto a = order[i];
      auto b = var_neg(order[i]);

      auto ac = components[a];
      auto bc = components[b];

      if (ac == bc)
        return {};

      comp_order[ac] = min(comp_order[ac], i);
      ans[a >> 1] = var_sign((comp_order[ac] < comp_order[bc] ? b : a));
    }
    return ans;
  }
};
