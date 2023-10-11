#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

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
  for (auto x : order)
    if (components[x] == -1)
    {
      components[x] = x;
      mark_component(gr, components, x);
    }
  return components;
}

struct Sat2
{
  vector<vector<int>> g, gr;

  Sat2(int variables) : g(variables << 1), gr(variables << 1) {}

  void add_clause(int x, bool sign_x, int y, bool sign_y)
  {
    g[var(x, not sign_x)].push_back(var(y, sign_y));
    g[var(y, not sign_y)].push_back(var(x, sign_x));

    gr[var(y, sign_y)].push_back(var(x, not sign_x));
    gr[var(x, sign_x)].push_back(var(y, not sign_y));
  }

  inline int var(int x, bool sign) const { return (x << 1) + sign; }
  inline int var_neg(int v) const { return v ^ 1; }
  inline bool var_sign(int v) const { return v & 1; }

  vector<bool> solve()
  {
    auto order = topological_order(g);
    auto components = mark_components(gr, order);
    vector<int> comp_order(components.size(), (int)g.size());
    vector<bool> ans(g.size() >> 1);
    for (int i = 0; i < (int)g.size(); i++)
    {
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

  Sat2 st(m);
  for (int i = 0; i < n; i++)
  {
    char a, b; int x, y;
    cin >> a >> x >> b >> y;
    st.add_clause(x-1, a=='+', y-1, b=='+');
  }

  auto ans = st.solve();
  if (ans.empty())
    cout << "IMPOSSIBLE\n";
  else
  {
    for (auto x : ans)
      cout << "-+"[x] << ' ';
    cout << '\n';
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
