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
