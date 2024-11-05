template <typename T> struct PrefixSum2d {
  vector<vector<T>> pref;
  PrefixSum2d() {}
  PrefixSum2d(const vector<vector<T>> &mat) { build(mat); }
  void build(const vector<vector<T>> &mat) {
    const int n = (int)mat.size();
    const int m = (int)mat[0].size();
    pref.resize(n+1, vector<T>(m+1));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        pref[i+1][j+1] = pref[i+1][j] + pref[i][j+1] - pref[i][j] + mat[i][j];
  }
  T query(int x1, int y1, int x2, int y2) const {
    return pref[x2+1][y2+1] - pref[x2+1][y1] - pref[x1][y2+1] + pref[x1][y1];
  }
};
