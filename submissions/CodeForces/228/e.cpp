#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void topological_order(const vector<vector<int>> &g, vector<char> &vis, vector<int> &order, int s)
{
  vis[s] = true;
  for (auto x : g[s])
    if (not vis[x])
      topological_order(g, vis, order, x);
  order.push_back(s);
}

vector<int> topological_order(const vector<vector<int>> &g)
{
  vector<char> vis(g.size(), false);
  vector<int> order;
  for (auto i = 0; i < (int)g.size(); i++)
    if (not vis[i])
      topological_order(g, vis, order, i);
  reverse(order.begin(), order.end());
  return order;
}

void mark_component(const vector<vector<int>> &gr, vector<int> &component, int s)
{
  for (auto x : gr[s])
    if (component[x] == -1)
    {
      component[x] = component[s];
      mark_component(gr, component, x);
    }
}

vector<int> mark_components(const vector<vector<int>> &gr, const vector<int> &order)
{
  vector<int> components(gr.size(), -1);
  int cur = 0;
  for (auto x : order)
    if (components[x] == -1)
    {
      components[x] = cur++;
      mark_component(gr, components, x);
    }
  return components;
}

vector<set<int>> components_tree(const vector<vector<int>> &g, const vector<int> &components)
{
  int n = (int)g.size();
  vector<set<int>> tree(*max_element(all(components))+1);
  for (int i = 0; i < n; i++)
  {
    for (auto x : g[i])
      if (components[i] != components[x])
        tree[components[i]].insert(components[x]);
  }
  return tree;
}

vector<set<int>> components_tree(const vector<vector<int>> &g, const vector<vector<int>> &gr)
{
  return components_tree(g, mark_components(gr, topological_order(g)));
}

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

void solve()
{
  int n, m;
  cin >> n >> m;
  Sat2 sat(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    if (w) {
      sat.add_implication(u, 0, v, 0);
      sat.add_implication(v, 0, u, 0);
      sat.add_implication(u, 1, v, 1);
      sat.add_implication(v, 1, u, 1);
    } else {
      sat.add_xor(u, 0, v, 0);
    }
  }

  auto res = sat.solve();
  if (res.empty()) {
    cout << "Impossible\n";
  } else {
    cout << accumulate(all(res), 0) << '\n';
    for (int i = 0; i < n; i++) {
      if (res[i])
        cout << i+1 << ' ';
    }
    cout << '\n';
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

