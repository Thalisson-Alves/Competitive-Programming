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
  int operator<=>(const modint &o) { return o.v - v; }
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
  static vector<T> fact{1, 1};
  while ((int)size(fact) <= n) fact.push_back(fact.back() * size(fact));
  return fact[n];
}
template <typename T=mint> T factorial_inv(int n) {
  static vector<T> inv{1, 1}, finv{1, 1};
  while ((int)size(inv) <= n) {
    inv.push_back(T::mod - T::mod / size(inv) * inv[T::mod % size(inv)].value() % T::mod);
    finv.push_back(finv.back() * inv.back());
  }
  return finv[n];
}

void solve() {
  string a, b;
  cin >> a >> b;
  const int n = (int)a.size();
  array<int, 26> hist;
  hist.fill(0);
  for (auto c : a) hist[c-'a']++;
  mint res, dem = 1;
  for (auto x : hist) if (x) dem *= factorial(x);
  for (int i = 0, eq = 1; i < n-1; eq &= a[i] == b[i], i++) {
    mint tot = factorial(n-i-1);
    for (int j = a[i]-'a'+1; j < (eq ? b[i]-'a' : 26); j++) if (hist[j])
      res += tot / (dem * factorial_inv(hist[j]) * factorial(hist[j]-1));
    dem *= factorial_inv(hist[a[i]-'a']--);
    dem *= factorial(hist[a[i]-'a']);
  }
  hist.fill(0);
  for (auto c : a) hist[c-'a']++;
  dem = 1;
  for (auto x : hist) if (x) dem *= factorial(x);
  for (int i = 0, eq = 1; i < n; eq &= a[i] == b[i], i++) {
    if (!eq) {
      mint tot = factorial(n-i-1);
      for (int j = 0; j < b[i]-'a'; j++) if (hist[j])
        res += tot / (dem * factorial_inv(hist[j]) * factorial(hist[j]-1));
    }
    if (!hist[b[i]-'a']) break;
    dem *= factorial_inv(hist[b[i]-'a']--);
    dem *= factorial(hist[b[i]-'a']);
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
