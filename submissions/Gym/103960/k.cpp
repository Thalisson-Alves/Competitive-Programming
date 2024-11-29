#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <ll Mod> struct modint {
  static constexpr ll mod = Mod;
  ll v;
  modint() : v(0) {}
  template <ll Mod2> modint(const modint<Mod2> &x) : v(x.value()) {}
  modint(ll x) : v(safe_mod(x)) {}
  ll &value() { return v; }
  const ll &value() const { return v; }
  static ll safe_mod(ll x) { return x >= 0 ? x % mod : ((x % mod) + mod) % mod; }
  template <typename T> explicit operator T() const { return (T)v; }
  bool operator==(const modint rhs) const noexcept { return v == rhs.v; }
  bool operator!=(const modint rhs) const noexcept { return v != rhs.v; }
  bool operator<(const modint rhs) const noexcept { return v < rhs.v; }
  bool operator<=(const modint rhs) const noexcept { return v <= rhs.v; }
  bool operator>(const modint rhs) const noexcept { return v > rhs.v; }
  bool operator>=(const modint rhs) const noexcept { return v >= rhs.v; }
  modint operator++(int) { modint res = *this; *this += 1; return res; }
  modint operator--(int) { modint res = *this; *this -= 1; return res; }
  modint &operator++() { return *this += 1; }
  modint &operator--() { return *this -= 1; }
  modint operator+() const { return modint(*this); }
  modint operator-() const { return modint(*this).negate(); }
  friend modint operator+(const modint lhs, const modint rhs) noexcept { return modint(lhs) += rhs; }
  friend modint operator-(const modint lhs, const modint rhs) noexcept { return modint(lhs) -= rhs; }
  friend modint operator*(const modint lhs, const modint rhs) noexcept { return modint(lhs) *= rhs; }
  friend modint operator/(const modint lhs, const modint rhs) noexcept { return modint(lhs) /= rhs; }
  modint &operator+=(const modint rhs) { v += rhs.v; if (v >= mod) v -= mod; return *this; }
  modint &operator-=(const modint rhs) { if (v < rhs.v) v += mod; v -= rhs.v; return *this; }
  modint &operator*=(const modint rhs) { v = v * rhs.v % mod; return *this; }
  modint &operator/=(modint rhs) { return *this *= rhs.inv(); }
  modint pow(ll p) const {
    static_assert(mod < static_cast<ll>(1) << 32, "Modulus must be less than 2**32");
    modint res = 1, a = *this;
    while (p) {
      if (p & 1) res *= a;
      a *= a;
      p >>= 1;
    }
    return res;
  }
  modint inv() const { return pow(mod - 2); }
  modint sqrt() const {
    modint b = 1;
    while (b.pow((mod - 1) >> 1) == 1) b += 1;
    ll m = mod-1, e = 0;
    while (~m&1) m >>= 1, e++;
    auto x = pow((m-1)>>1);
    auto y = *this * x * x;
    x *= *this;
    auto z = b.pow(m);
    while (y != 1) {
      ll j = 0;
      for (modint t = y; t != 1; t *= t, ++j);
      z.pow(1ll << (e - j - 1));
      x *= z;
      z *= z;
      y *= z;
      e = j;
    }
    return x;
  }
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
using mint = modint<1000000000>;

template <typename T> struct Poly {
  vector<T> ps;
  Poly() {}
  Poly(int n) : ps(n) {}
  Poly &operator+=(const Poly &o) {
    for (int i = 0; i < (int)ps.size(); i++) ps[i] += o.ps[i];
    return *this;
  }
  Poly operator+(const Poly &o) const { return Poly(*this) += o; }
  Poly &operator*=(const Poly &o) {
    vector<T> res(ps.size());
    for (int i = 0; i < (int)ps.size(); i++)
      for (int j = 0; j < (int)ps.size(); j++)
        if (i + j < (int)ps.size())
          res[i+j] += ps[i] * o.ps[j];
    swap(ps, res);
    assert(ps.size());
    return *this;
  }
  Poly operator*(const Poly &o) const { return Poly(*this) *= o; }
  T &operator[](int i) { return ps[i]; }
  const T &operator[](int i) const { return ps[i]; }
  friend ostream &operator<<(ostream &os, const Poly &p) {
    for (int i = 0; i < (int)p.ps.size(); i++)
      os << p.ps[i] << " \n"[i == (int)p.ps.size()-1];
    return os;
  }
};

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  using T = Poly<mint>;
  using Matrix = vector<vector<T>>;
  Matrix mat(11, vector<T>(11, k+1));
  for (int i = 1; i < 11; i++) mat[i][i-1][0] = 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    mat[0][a-1][b]++;
  }
  auto prod = [&](Matrix &a, const Matrix &b) {
    Matrix res(a.size(), vector<T>(b[0].size(), k+1));
    for (int i = 0; i < 11; i++)
      for (int j = 0; j < 11; j++)
        for (int l = 0; l < 11; l++)
          res[i][l] += (a[i][j] * b[j][l]);
    swap(a, res);
  };
  auto fpow = [&](Matrix &x, ll p) {
    Matrix res(11, vector<T>(11, k+1));
    for (int i = 0; i < 11; i++) res[i][i][0] = 1;
    while (p) {
      if (p & 1) prod(res, x);
      prod(x, x);
      p >>= 1;
    }
    swap(res, x);
  };
  fpow(mat, n-1);
  mint res = 0;
  for (int i = 0; i <= k; i++)
    res += mat[0][0][i];
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
