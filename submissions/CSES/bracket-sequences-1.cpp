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
  modint() noexcept : v(0) {}
  template <u64 Mod2> modint(const modint<Mod2> &x) : v(x.value()) {}
  template <typename T> modint(const T x) noexcept : v(safe_mod(x)) {}
  u64 &value() noexcept { return v; }
  const u64 &value() const noexcept { return v; }
  template <typename T> static u64 safe_mod(T x) noexcept {
    if constexpr (is_signed_v<T>) {
      return (x % (ll)mod + mod) % mod;
    } else {
      return x % mod;
    }
  }
  bool operator==(const modint rhs) const noexcept { return v == rhs.v; }
  bool operator!=(const modint rhs) const noexcept { return v != rhs.v; }
  bool operator<(const modint rhs) const noexcept { return v < rhs.v; }
  bool operator<=(const modint rhs) const noexcept { return v <= rhs.v; }
  bool operator>(const modint rhs) const noexcept { return v > rhs.v; }
  bool operator>=(const modint rhs) const noexcept { return v >= rhs.v; }
  template <typename T> explicit operator T() const noexcept { return (T)v; }
  modint operator++(int) noexcept { modint res = *this; *this += 1; return res; }
  modint operator--(int) noexcept { modint res = *this; *this -= 1; return res; }
  modint &operator++() noexcept { return *this += 1; }
  modint &operator--() noexcept { return *this -= 1; }
  modint operator+() const noexcept { return modint(*this); }
  modint operator-() const noexcept { return modint(*this).negate(); }
  friend modint operator+(const modint lhs, const modint rhs) noexcept { return modint(lhs) += rhs; }
  friend modint operator-(const modint lhs, const modint rhs) noexcept { return modint(lhs) -= rhs; }
  friend modint operator*(const modint lhs, const modint rhs) noexcept { return modint(lhs) *= rhs; }
  friend modint operator/(const modint lhs, const modint rhs) noexcept { return modint(lhs) /= rhs; }
  modint &operator+=(const modint rhs) noexcept {
    v += rhs.v;
    if (v >= mod) v -= mod;
    return *this;
  }
  modint &operator-=(const modint rhs) noexcept {
    if (v < rhs.v) v += mod;
    v -= rhs.v;
    return *this;
  }
  modint &operator*=(const modint rhs) noexcept {
    v = v * rhs.v % mod;
    return *this;
  }
  modint &operator/=(modint rhs) noexcept { return *this *= rhs.inv(); }
  modint pow(u64 x) const {
    static_assert(mod < static_cast<u64>(1) << 32, "Modulus must be less than 2**32");
    modint res = 1, a = *this;
    while (x) {
      if (x & 1) res *= a;
      a *= a;
      x >>= 1;
    }
    return res;
  }
  modint sqrt() const {
    modint b = 1;
    while (b.pow((mod - 1) >> 1) == 1) b += 1;
    u64 m = mod-1, e = 0;
    while (~m&1) m >>= 1, e++;
    auto x = pow((m-1)>>1);
    auto y = *this * x * x;
    x *= *this;
    auto z = b.pow(m);
    while (y != 1) {
      u64 j = 0;
      for (modint t = y; t != 1; t *= t, ++j);
      z.pow(1ll << (e - j - 1));
      x *= z;
      z *= z;
      y *= z;
      e = j;
    }
    return x;
  }
  inline modint inv() const { return pow(mod - 2); }
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

template <typename T=mint> T factorial(int n) {
  static vector<T> fact{1};
  while ((int)size(fact) <= n) fact.push_back(fact.back() * size(fact));
  return fact[n];
}
template <typename T=mint> T comb(int n, int k) {
  return factorial<T>(n) / (factorial<T>(n-k) * factorial<T>(k));
}
template <typename T=mint> T catalan(int n) {
  return comb<T>(2*n, n) / (n + 1);
}

void solve() {
  int n;
  cin >> n;
  if (n&1) {
    cout << "0\n";
    return;
  }
  cout << catalan(n>>1) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
