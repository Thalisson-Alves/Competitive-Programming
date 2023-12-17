template <bool directed = false, typename T>
bool check_cycle(const T &g, int u, int p, vector<int> &color)
{
  if (color[u] == 2) {
    return false;
  }

  if (color[u] == 1) {
    return true;
  }

  color[u] = 1;
  for (auto v : g[u]) if (v != p) {
    if (check_cycle(g, v, (directed ? p : u), color)) {
      return true;
    }
  }

  color[u] = 2;
  return false;
}

template <bool directed = false, typename T>
bool check_cycle(const T &g) {
  vector<int> color(g.size());
  for (int i = 0; i < (int)g.size(); i++)
    if (check_cycle<directed>(g, i, -1, color))
      return true;
  return false;
}
