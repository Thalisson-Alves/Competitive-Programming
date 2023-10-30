void tree_flatten(const vector<vector<int>> &g, int u, int p, vector<int> &pre, vector<pair<int,int>> &pos, int &idx) {
  ++idx;
  pre.push_back(u);
  for (auto x : g[u])
    if (x != p)
      tree_flatten(g, x, u, pre, pos, idx);
  pos[u].second = idx;
}

vector<pair<int, int>> tree_flatten(const vector<vector<int>> &g, int root=0) {
  vector<int> pre;
  pre.reserve(g.size());
  vector<pair<int, int>> flat(g.size());
  int timer = -1;
  tree_flatten(g, root, -1, pre, flat, timer);
  for (int i = 0; i < (int)g.size(); i++)
    flat[pre[i]].first = i;
  return flat;
}
