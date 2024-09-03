#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

template <uint_fast64_t Modulus> class modint {
  using u64 = uint_fast64_t;
public:
  using value_type = u64;
  static constexpr u64 mod = Modulus;
private:
  u64 v;
  constexpr modint &negate() noexcept {
    if (v != 0) v = mod - v;
    return *this;
  }
public:
  constexpr modint() noexcept : v(0) {}
  template <typename T> constexpr modint(const T x) noexcept : v(safe_mod(x)) {}
  constexpr u64 &value() noexcept { return v; }
  constexpr const u64 &value() const noexcept { return v; }
  template <typename T> static constexpr u64 safe_mod(T x) noexcept {
    if constexpr (is_signed_v<T>) {
      return (x % (ll)mod + mod) % mod;
    } else {
      return x % mod;
    }
  }
  constexpr bool operator==(const modint rhs) const noexcept { return v == rhs.v; }
  constexpr bool operator!=(const modint rhs) const noexcept { return v != rhs.v; }
  constexpr bool operator<(const modint rhs) const noexcept { return v < rhs.v; }
  constexpr bool operator<=(const modint rhs) const noexcept { return v <= rhs.v; }
  constexpr bool operator>(const modint rhs) const noexcept { return v > rhs.v; }
  constexpr bool operator>=(const modint rhs) const noexcept { return v >= rhs.v; }
  template <typename T> constexpr explicit operator T() const noexcept { return (T)v; }
  constexpr modint operator++(int) noexcept { modint res = *this; *this += 1; return res; }
  constexpr modint operator--(int) noexcept { modint res = *this; *this -= 1; return res; }
  constexpr modint &operator++() noexcept { return *this += 1; }
  constexpr modint &operator--() noexcept { return *this -= 1; }
  constexpr modint operator+() const noexcept { return modint(*this); }
  constexpr modint operator-() const noexcept { return modint(*this).negate(); }
  friend constexpr modint operator+(const modint lhs, const modint rhs) noexcept { return modint(lhs) += rhs; }
  friend constexpr modint operator-(const modint lhs, const modint rhs) noexcept { return modint(lhs) -= rhs; }
  friend constexpr modint operator*(const modint lhs, const modint rhs) noexcept { return modint(lhs) *= rhs; }
  friend constexpr modint operator/(const modint lhs, const modint rhs) noexcept { return modint(lhs) /= rhs; }
  constexpr modint &operator+=(const modint rhs) noexcept {
    v += rhs.v;
    if (v >= mod) v -= mod;
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (v < rhs.v) v += mod;
    v -= rhs.v;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    v = v * rhs.v % mod;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept { return *this * rhs.inv(); }
  constexpr modint pow(u64 x) const {
    static_assert(mod < static_cast<u64>(1) << 32, "Modulus must be less than 2**32");
    modint res = 1, a = *this;
    while (x) {
      if (x & 1) res *= a;
      a *= a;
      x >>= 1;
    }
    return res;
  }
  constexpr inline modint inv() const { return pow(mod - 2); }
  friend ostream& operator<<(ostream& s, const modint &x) {
    s << x.value();
    return s;
  }
  friend istream& operator>>(istream& s, modint& x) {
    ll value;
    s >> value;
    x = {value};
    return s;
  }
};
template <uint_fast64_t Modulus>
constexpr typename modint<Modulus>::u64 modint<Modulus>::mod;
using mint = modint<1000000007>;

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
  Matrix<T> pow(ll power) const {
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
        if (not first) os << ' ';
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
  int n; ll k;
  cin >> n >> k;
  vector<mint> a(n), c(n);
  for (auto &x : a) cin >> x;
  for (auto &x : c) cin >> x;
  int p, q, r;
  cin >> p >> q >> r;
  if (k < n) {
    cout << a[k] << '\n';
    return;
  }
  Matrix<mint> mat(n+3);
  for (int i = 0; i < n-1; i++) mat[i+1][i] = 1;
  for (int i = 0; i < n; i++) mat[n-i-1][n-1] = c[i];
  mat[n][n-1] = p;
  mat[n+1][n-1] = q;
  mat[n+2][n-1] = r;
  mat[n][n] = 1;
  mat[n+1][n+1] = mat[n][n+1] = 1;
  mat[n+2][n+2] = mat[n][n+2] = 1;
  mat[n+1][n+2] = 2;
  a.push_back(1);
  a.push_back(n);
  a.push_back(n*n);
  cout << (Matrix<mint>(vector<vector<mint>>(1, a)) * mat.pow(k-n+1))[0][n-1] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
