inline void floyd_warshall(vector<vector<ll>> &d) {
  int n = static_cast<int>(d.size());
  for (int i = 0; i < n; i++)
    d[i][i] = 0;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][k] < LLONG_MAX and d[k][j] < LLONG_MAX)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}
