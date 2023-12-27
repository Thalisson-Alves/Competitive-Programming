constexpr int dir4[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
constexpr int dir8[][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
constexpr int dir_knight[][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
template <typename T> Digraph<T> make_gridgraph(const vector<vector<T>> &grid, const auto &dirs) {
  int n = (int)grid.size(), m = (int)grid[0].size();
  Digraph<T> g(n * m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      for (auto [dx, dy] : dirs) {
        int x = i + dx, y = j + dy;
        if (0 <= x and x < n and 0 <= y and y < m)
          g.add_edge(i * m + j, x * m + y, grid[i][j]);
      }
    }
  return g;
}
Digraph<int> make_gridgraph(const vector<string> &grid, const char wall, const auto &dirs) {
  int n = (int)grid.size(), m = (int)grid[0].size();
  Digraph<int> g(n * m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == wall) continue;
      for (auto [dx, dy] : dirs) {
        int x = i + dx, y = j + dy;
        if (0 <= x and x < n and 0 <= y and y < m and grid[x][y] != wall)
          g.add_edge(i * m + j, x * m + y);
      }
    }
  return g;
}
