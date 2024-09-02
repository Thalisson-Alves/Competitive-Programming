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
