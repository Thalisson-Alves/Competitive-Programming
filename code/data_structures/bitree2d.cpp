template<typename T> struct BITree2d {
  int N, M;
  vector<vector<T>> vs;

  BITree2d(int n, int m) : N(n), M(m), vs(n+1, vector<T>(m+1)) {}
  BITree2d(const vector<vector<T>> &v) : BITree2d((int)v.size(), (int)v[0].size()) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        update(i, j, v[i][j]);
      }
    }
  }

  void update(int x, int y, const T& v) {
    for (++x; x <= N; x += x & -x)
      for (int i = y + 1; i <= M; i += i & -i)
        vs[x][i] += v;
  }

  T query(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1);
  }

  T query(int x, int y) {
    if (x < 0 || y < 0) return T();

    T sum = 0;
    for (int i = x+1; i; i -= i & -i)
      for (int j = y+1; j; j -= j & -j)
        sum += vs[i][j];
    return sum;
  }
};
