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
  Matrix(const vector<T> &v) : d(vector<vector<T>>(1, v)) {}
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
    for (auto &row : d) {
      for (auto &x : row)
        x += value;
    }
    return *this;
  }
  Matrix<T> operator-(T value) const { return Matrix(*this) -= value; }
  Matrix<T> &operator-=(T value) {
    for (auto &row : d) {
      for (auto &x : row)
        x -= value;
    }
    return *this;
  }
  Matrix<T> operator*(T value) const { return Matrix(*this) *= value; }
  Matrix<T> &operator*=(T value) {
    for (auto &row : d) {
      for (auto &x : row)
        x *= value;
    }
    return *this;
  }
  Matrix<T> &operator/=(T value) {
    for (auto &row : d) {
      for (auto &x : row)
        x /= value;
    }
    return *this;
  }
  Matrix<T> operator/(T value) const { return Matrix(*this) /= value; }
  Matrix<T> &operator+=(const Matrix<T> &o) {
    assert(n() == o.n() and m() == o.m());
    for (int i = 0; i < n(); i++) {
      for (int j = 0; j < m(); j++) {
        d[i][j] += o[i][j];
      }
    }
    return *this;
  }
  Matrix<T> operator+(const Matrix<T> &o) const { return Matrix(o) += o; }
  Matrix<T> &operator-=(const Matrix<T> &o) {
    assert(n() == o.n() and m() == o.m());
    for (int i = 0; i < n(); i++) {
      for (int j = 0; j < m(); j++) {
        d[i][j] -= o[i][j];
      }
    }
    return *this;
  }
  Matrix<T> operator-(const Matrix<T> &o) const { return Matrix(*this) -= o; }
  Matrix<T> operator*(const Matrix<T> &o) const { return Matrix(*this) *= o; }
  friend Matrix<T> operator*(const vector<T> &a, const Matrix<T> &o) { return Matrix(a) *= o; }
  Matrix<T> &operator*=(const Matrix<T> &o) {
    assert(m() == o.n());
    Matrix<T> res(n(), o.m());
    for (int i = 0; i < res.n(); i++) {
      for (int j = 0; j < res.m(); j++) {
        for (int k = 0; k < m(); k++) {
          res[i][k] += (d[i][j] * o[j][k]);
        }
      }
    }
    swap(d, res.d);
    return *this;
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
  int n, m, q;
  cin >> n >> m >> q;
  Matrix<mint> mat(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    mat[--u][--v]++;
  }
  vector<Matrix<mint>> pows(30);
  pows[0] = mat;
  for (int i = 1; i < 30; i++) pows[i] = mat.ipow(2);
  while (q--) {
    int s, t, k;
    cin >> s >> t >> k;
    --s, --t, --k;
    Matrix<mint> res(pows[0][s]);
    for (int i = 0; i < 30; i++) {
      if (k>>i&1) res*=pows[i];
    }
    cout << res[0][t] << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
