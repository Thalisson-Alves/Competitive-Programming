#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

/*
Used to define recursive lambdas,  first argument is the function itself

auto value = y_combinator([](auto &&gcd, int a, int b) -> int {
  return b ? gcd(b, a % b) : a;
});
*/
template <class Fun> class y_combinator_result {
  Fun fun_;

  public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template <typename T> struct Matrix {
  vector<vector<T>> d;

  Matrix() : Matrix(0) {}
  Matrix(int n) : Matrix(n, n) {}
  Matrix(int n, int m) : Matrix(vector<vector<T>>(n, vector<T>(m))) {}
  Matrix(const vector<vector<T>> &v) : d(v) {}

  constexpr int n() const { return (int)d.size(); }
  constexpr int m() const { return n() ? (int)d[0].size() : 0; }

  void rotate() { *this = rotated(); }

  Matrix<T> rotated() const {
    Matrix<T> res(m(), n());
    for (int i = 0; i < m(); i++) {
      for (int j = 0; j < n(); j++) {
        res[i][j] = d[n()-j-1][i];
      }
    }
    return res;
  }

  Matrix<T> fpow(int power) const {
    assert(n() == m());

    auto res = Matrix<T>::identity(n());
    auto b = *this;
    while (power) {
      if (power & 1) res *= b;
      b *= b;
      power >>= 1;
    }
    return res;
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
    for (int i = 0; i < n; i++)
      res[i][i] = 1;
    return res;
  }

  vector<T> &operator[](int i) { return d[i]; }
  const vector<T> &operator[](int i) const { return d[i]; }
  Matrix<T> &operator+=(T value) {
    for (auto &row : d) {
      for (auto &x : row)
        x += value;
    }
    return *this;
  }
  Matrix<T> operator+(T value) const {
    auto res = *this;
    for (auto &row : res) {
      for (auto &x : row)
        x = x + value;
    }
    return res;
  }
  Matrix<T> &operator-=(T value) {
    for (auto &row : d) {
      for (auto &x : row)
        x -= value;
    }
    return *this;
  }
  Matrix<T> operator-(T value) const {
    auto res = *this;
    for (auto &row : res) {
      for (auto &x : row)
        x = x - value;
    }
    return res;
  }
  Matrix<T> &operator*=(T value) {
    for (auto &row : d) {
      for (auto &x : row)
        x *= value;
    }
    return *this;
  }
  Matrix<T> operator*(T value) const {
    auto res = *this;
    for (auto &row : res) {
      for (auto &x : row)
        x = x * value;
    }
    return res;
  }
  Matrix<T> &operator/=(T value) {
    for (auto &row : d) {
      for (auto &x : row)
        x /= value;
    }
    return *this;
  }
  Matrix<T> operator/(T value) const {
    auto res = *this;
    for (auto &row : res) {
      for (auto &x : row)
        x = x / value;
    }
    return res;
  }
  Matrix<T> &operator+=(const Matrix<T> &o) {
    assert(n() == o.n() and m() == o.m());
    for (int i = 0; i < n(); i++) {
      for (int j = 0; j < m(); j++) {
        d[i][j] += o[i][j];
      }
    }
    return *this;
  }
  Matrix<T> operator+(const Matrix<T> &o) const {
    assert(n() == o.n() and m() == o.m());
    auto res = *this;
    for (int i = 0; i < n(); i++) {
      for (int j = 0; j < m(); j++) {
        res[i][j] = res[i][j] + o[i][j];
      }
    }
    return res;
  }
  Matrix<T> &operator-=(const Matrix<T> &o) {
    assert(n() == o.n() and m() == o.m());
    for (int i = 0; i < n(); i++) {
      for (int j = 0; j < m(); j++) {
        d[i][j] -= o[i][j];
      }
    }
    return *this;
  }
  Matrix<T> operator-(const Matrix<T> &o) const {
    assert(n() == o.n() and m() == o.m());
    auto res = *this;
    for (int i = 0; i < n(); i++) {
      for (int j = 0; j < m(); j++) {
        res[i][j] = res[i][j] - o[i][j];
      }
    }
    return res;
  }
  Matrix<T> &operator*=(const Matrix<T> &o) {
    *this = *this * o;
    return *this;
  }
  Matrix<T> operator*(const Matrix<T> &o) const {
    assert(m() == o.n());
    Matrix<T> res(n(), o.m());
    for (int i = 0; i < res.n(); i++) {
      for (int j = 0; j < res.m(); j++) {
        auto &x = res[i][j];
        for (int k = 0; k < m(); k++) {
          x += (d[i][k] * o[k][j]);
        }
      }
    }
    return res;
  }

  Matrix<T> pow(ll e) const {
    assert(n() == m());
    Matrix<T> res = identity(n());
    Matrix<T> b = *this;
    while (e) {
      if (e & 1) res *= b;
      b *= b;
      e >>= 1;
    }
    return res;
  }

  friend istream &operator>>(istream &is, Matrix<T> &mat) {
    for (auto &row : mat)
      for (auto &x : row)
        is >> x;
    return is;
  }
  friend ostream &operator<<(ostream &os, const Matrix<T> &mat) {
    bool frow = 1;
    for (auto &row : mat) {
      if (not frow) os << '\n';
      bool first = 1;
      for (auto &x : row) {
        if (not first)
          os << ' ';
        os << x;
        first = 0;
      }

      frow = 0;
    }
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

void solve() {
  for (int n, a, b, c; cin >> n >> a >> b >> c;) {
    --a, --b, --c;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    Matrix<double> prob(n);
    y_combinator([&](auto &&dfs, int u, int p) -> void {
      double value = 1.0 / (int)g[u].size();
      if (u == b or u == c) {
        prob[u][u] = 1.0;
        return;
      }
      for (auto x : g[u]) {
        prob[u][x] = value;
        if (x != p)
          dfs(x, u);
      }
    })(a, -1);

    cout << fixed << setprecision(6) << prob.pow(100'000)[a][b] << '\n';
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
