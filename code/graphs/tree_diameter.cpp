void tree_diameter(const vector<vector<int>> &g, int s, vector<int> &dist, int &last)
{
  for (auto x : g[s])
    if (dist[x] == -1)
    {
      if ((dist[x] = dist[s] + 1) > dist[last])
        last = x;
      tree_diameter(g, x, dist, last);
    }
}

int tree_diameter(const vector<vector<int>> &g)
{
  vector<int> dist(g.size(), -1);
  int last = 0;
  dist[last] = 0;
  tree_diameter(g, last, dist, last);

  dist.assign(g.size(), -1);
  dist[last] = 0;
  tree_diameter(g, last, dist, last);

  return dist[last];
}
