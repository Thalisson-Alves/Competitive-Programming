template <typename T> struct Matrix {
  vector<vector<T>> d;
  Matrix() : Matrix(0) {}
  Matrix(int n) : Matrix(n, n) {}
  Matrix(int n, int m) : Matrix(vector<vector<T>>(n, vector<T>(m))) {}
  Matrix(const initializer_list<T> &v) : Matrix(vector<T>(v)) {}
  Matrix(const initializer_list<vector<T>> &v) : Matrix(vector<vector<T>>(v)) {}
  Matrix(const vector<T> &v) : d(vector<vector<T>>(1, v)) {}
  Matrix(const vector<vector<T>> &v) : d(v) {}
  constexpr int n() const { return (int)d.size(); }
  constexpr int m() const { return n() ? (int)d[0].size() : 0; }
  void rotate() { *this = rotated(); }
  Matrix<T> rotated() const {
    Matrix<T> res(m(), n());
    for (int i = 0; i < m(); i++)
      for (int j = 0; j < n(); j++)
        res[i][j] = d[n()-j-1][i];
    return res;
  }
  Matrix<T> pow(ll p) { return Matrix<T>(*this).ipow(p); }
  Matrix<T> &ipow(ll p) {
    assert(n() == m());
    auto res = Matrix<T>::identity(n());
    while (p) {
      if (p & 1) res *= *this;
      *this *= *this;
      p >>= 1;
    }
    swap(res.d, d);
    return *this;
  }
  Matrix<T> submatrix(int start_i, int start_j, int rows = INT_MAX, int cols = INT_MAX) const {
    rows = min(rows, n() - start_i);
    cols = min(cols, m() - start_j);
    if (rows <= 0 or cols <= 0) return {};
    Matrix<T> res(rows, cols);
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        res[i][j] = d[i+start_i][j+start_j];
    return res;
  }
  Matrix<T> translated(int x, int y) const {
    Matrix<T> res(n(), m());
    for (int i = 0; i < n(); i++) {
      for (int j = 0; j < m(); j++) {
        if (i+x < 0 or i+x >= n() or j+y < 0 or j+y >= m()) continue;
        res[i+x][j+y] = d[i][j];
      }
    }
    return res;
  }
  static Matrix<T> identity(int n) {
    Matrix<T> res(n);
    for (int i = 0; i < n; i++) res[i][i] = 1;
    return res;
  }
  vector<T> &operator[](int i) { return d[i]; }
  const vector<T> &operator[](int i) const { return d[i]; }
  Matrix<T> operator+(T value) const { return Matrix(*this) += value; }
  Matrix<T> &operator+=(T value) {
    for (auto &row : d) for (auto &x : row) x += value;
    return *this;
  }
  Matrix<T> operator-(T value) const { return Matrix(*this) -= value; }
  Matrix<T> &operator-=(T value) {
    for (auto &row : d) for (auto &x : row) x -= value;
    return *this;
  }
  Matrix<T> operator*(T value) const { return Matrix(*this) *= value; }
  Matrix<T> &operator*=(T value) {
    for (auto &row : d) for (auto &x : row) x *= value;
    return *this;
  }
  Matrix<T> &operator/=(T value) {
    for (auto &row : d) for (auto &x : row) x /= value;
    return *this;
  }
  Matrix<T> operator/(T value) const { return Matrix(*this) /= value; }
  Matrix<T> &operator+=(const Matrix<T> &o) {
    assert(n() == o.n() and m() == o.m());
    for (int i = 0; i < n(); i++)
      for (int j = 0; j < m(); j++)
        d[i][j] += o[i][j];
    return *this;
  }
  Matrix<T> operator+(const Matrix<T> &o) const { return Matrix(o) += o; }
  Matrix<T> &operator-=(const Matrix<T> &o) {
    assert(n() == o.n() and m() == o.m());
    for (int i = 0; i < n(); i++)
      for (int j = 0; j < m(); j++)
        d[i][j] -= o[i][j];
    return *this;
  }
  Matrix<T> operator-(const Matrix<T> &o) const { return Matrix(*this) -= o; }
  Matrix<T> operator*(const Matrix<T> &o) const { return Matrix(*this) *= o; }
  friend Matrix<T> operator*(const vector<T> &a, const Matrix<T> &o) { return Matrix(a) *= o; }
  Matrix<T> &operator*=(const Matrix<T> &o) {
    assert(m() == o.n());
    Matrix<T> res(n(), o.m());
    for (int i = 0; i < res.n(); i++)
      for (int j = 0; j < res.m(); j++)
        for (int k = 0; k < m(); k++)
          res[i][k] += (d[i][j] * o[j][k]);
    swap(d, res.d);
    return *this;
  }
  friend istream &operator>>(istream &is, Matrix<T> &mat) {
    for (auto &row : mat) for (auto &x : row) is >> x;
    return is;
  }
  friend ostream &operator<<(ostream &os, const Matrix<T> &mat) {
    for (int i = 0; i < mat.n(); i++)
      for (int j = 0; j < mat.m(); j++)
        os << mat[i][j] << " \n"[j == mat.m()-1];
    return os;
  }
  auto begin() { return d.begin(); }
  auto end() { return d.end(); }
  auto rbegin() { return d.rbegin(); }
  auto rend() { return d.rend(); }
  auto begin() const { return d.begin(); }
  auto end() const { return d.end(); }
  auto rbegin() const { return d.rbegin(); }
  auto rend() const { return d.rend(); }
};
