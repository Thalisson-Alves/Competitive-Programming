#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;

template <uint_fast64_t Modulus> class modint {
  using u64 = uint_fast64_t;

public:
  using value_type = u64;

  static constexpr u64 mod = Modulus;

private:
  static_assert(mod < static_cast<u64>(1) << 32, "Modulus must be less than 2**32");
  u64 v;

  constexpr modint &negate() noexcept {
    if (v != 0) v = mod - v;
    return *this;
  }

public:
  constexpr modint(const ll x = 0) noexcept : v(x % (int)mod + mod) { if (v >= mod) v -= mod; }
  constexpr u64 &value() noexcept { return v; }
  constexpr const u64 &value() const noexcept { return v; }
  constexpr modint operator+() const noexcept { return modint(*this); }
  constexpr modint operator-() const noexcept { return modint(*this).negate(); }
  constexpr modint operator+(const modint rhs) const noexcept { return modint(*this) += rhs; }
  constexpr modint operator-(const modint rhs) const noexcept { return modint(*this) -= rhs; }
  constexpr modint operator*(const modint rhs) const noexcept { return modint(*this) *= rhs; }
  constexpr modint operator/(const modint rhs) const noexcept { return modint(*this) /= rhs; }
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
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = mod - 2;
    while (exp != 0) {
      if (exp % 2 != 0) *this *= rhs;
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
  constexpr modint pow(u64 x) const {
    if (x == 0) return 1;
    auto ans = pow(x>>1);
    ans *= ans;
    if (x&1) ans *= v;
    return ans;
  }
  constexpr inline modint inv() const { return pow(mod - 2); }

  friend ostream& operator<<(ostream& s, const modint<mod>& x) {
    s << x.value();
    return s;
  }

  friend istream& operator>>(istream& s, modint<mod>& x) {
    s >> x.v;
    return s;
  }
};

template <uint_fast64_t Modulus>
constexpr typename modint<Modulus>::u64 modint<Modulus>::mod;
using mint = modint<998244353>;

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T, auto op> struct SegTree {
  static_assert(std::is_invocable_r_v<T, decltype(op), T, T>);

  int N;
  const T identity = T();
  vector<T> ns;

  SegTree(int n, const T identity_ = T()) : N(n), identity(identity_), ns(2 * N, identity)  {}

  SegTree(const vector<T> &v) : SegTree((int)v.size()) {
    copy(v.begin(), v.end(), ns.begin() + N);
    for (int i = N - 1; i > 0; --i)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }

  T query(size_t i) const {
    return ns[i + N];
  }

  T query(size_t l, size_t r) const {
    auto ml = identity, mr = identity;
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ml = op(ml, ns[l++]);
      if (not (r & 1)) mr = op(ns[r--], mr);
    }
    return op(ml, mr);
  }

  void update(size_t i, T value) {
    set(i, op(ns[i + N], value));
  }

  void set(size_t i, T value) {
    ns[i += N] = value;
    while (i >>= 1)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }
};

void solve() {
  int n;
  cin >> n;
  SegTree<mint, F(a+b)> seg1(2e5+1);
  SegTree<ll, F(a+b)> seg2(2e5+1);
  mint sum = 0;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    auto prev = 2 * x * seg2.query(0, x-1) * seg2.query(x) + seg2.query(x) * seg2.query(x) * x;
    seg1.update(x, x);
    seg2.update(x, 1);
    auto nxt = 2 * x * seg2.query(0, x-1) * seg2.query(x) + seg2.query(x) * seg2.query(x) * x;
    sum += nxt - prev;
    sum += seg1.query(x+1, 2e5) * 2;
    cout << sum / ((i+1) * (i+1)) << '\n';
  }
}

int32_t main() {
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
