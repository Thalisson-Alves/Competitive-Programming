bool has_cycle(const vector<vector<int>> &g, int s, vector<char> &vis, vector<char> &in_path, vector<int> *path = nullptr)
{
  vis[s] = in_path[s] = 1;
  if (path != nullptr)
    path->push_back(s);
  dbg(s, path);
  for (auto x : g[s])
  {
    if (!vis[x] && has_cycle(g, x, vis, in_path, path))
      return true;
    else if (in_path[x])
    {
      if (path != nullptr)
        path->push_back(x);
      return true;
    }
  }
  dbg(s, path);
  in_path[s] = 0;
  if (path != nullptr)
    path->pop_back();
  return false;
}
