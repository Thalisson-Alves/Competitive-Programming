#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

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
using mint = modint<1000000007>;

template <typename T=mint> T factorial(int n) {
  static vector<T> fact{1};
  while ((int)size(fact) <= n) fact.push_back(fact.back() * size(fact));
  return fact[n];
}
template <typename T=mint> T comb(int n, int k) {
  return factorial<T>(n) / (factorial<T>(n-k) * factorial<T>(k));
}
// same as comb(2*n, n) / (n + 1)
template <typename T=mint> T catalan(int n) {
  return factorial<T>(2*n) / (factorial<T>(n) * factorial<T>(n + 1));
}

void solve() {
  int n; string s;
  cin >> n >> s;
  int k = 0;
  for (auto c : s) {
    k += 2 * (c == '(') - 1;
    if (k < 0) {
      k = n;
      break;
    }
  }
  if (n&1 or k > n - (int)size(s)) {
    cout << "0\n";
    return;
  }
  n = (n-(int)size(s)-k)/2;
  cout << comb(2*n+k, n) * (k + 1) / (n + k + 1) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
