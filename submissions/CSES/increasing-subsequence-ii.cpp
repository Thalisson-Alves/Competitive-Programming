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
using mint = modint<1000000007>;

template <typename T, typename Op = function<T(T,T)>> struct SegTree {
  int size;
  vector<T> ns;
  const Op op;
  const T id = T();
  SegTree(int n, Op f = Op(), const T identity = T()) : op(f), id(identity) {
    size = 1;
    while (size < n) size <<= 1;
    ns.resize(size << 1, id);
  }
  SegTree(const vector<T> &v, Op f = Op(), const T identity = T()) : SegTree((int)v.size(), f, identity) {
    copy(v.begin(), v.end(), ns.begin() + size);
    for (int i = size - 1; i > 0; --i)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }
  T query(int i) const { return ns[i + size]; }
  T query(int l, int r) const {
    auto ml = id, mr = id;
    for (l += size, r += size; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ml = op(ml, ns[l++]);
      if (not (r & 1)) mr = op(ns[r--], mr);
    }
    return op(ml, mr);
  }
  void update(int i, T value) { set(i, op(ns[i + size], value)); }
  void set(int i, T value) {
    ns[i += size] = value;
    while (i >>= 1)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }
  template <typename F> int pos(F f) {
    int u = 1;
    if (!f(ns[u])) return -1;
    for (auto sm = id; u < size;) {
      u <<= 1;
      if (!f(op(sm, ns[u])))
        sm = op(sm, ns[u++]);
    }
    return u-size;
  }
  template <typename F> int find_right(int l, F f) {
    auto sm = id;
    l += size;
    do {
      while (!(l&1)) l >>= 1;
      if (f(op(sm, ns[l]))) {
        while (l < size) {
          l <<= 1;
          if (!f(op(sm, ns[l])))
            sm = op(sm, ns[l++]);
        }
        return l-size;
      }
      sm = op(sm, ns[l++]);
    } while ((l&-l) != l);
    return -1;
  }
  template <typename F> int find_left(int r, F f) {
    auto sm = id;
    r += size;
    do {
      while (r > 1 and (r&1)) r >>= 1;
      if (f(op(ns[r], sm))) {
        while (r < size) {
          r = r<<1|1;
          if (!f(op(ns[r], sm)))
            sm = op(ns[r--], sm);
        }
        return r-size;
      }
      sm = op(ns[r--], sm);
    } while (r&(r+1));
    return -1;
  }
};

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  auto compress = a;
  sort(begin(compress), end(compress));
  compress.erase(unique(begin(compress), end(compress)), end(compress));
  SegTree<mint, plus<mint>> seg((int)size(compress)+1);
  seg.set(0, 1);
  for (int i = 0; i < n; i++) {
    int cur_comp = int(lower_bound(begin(compress), end(compress), a[i])-begin(compress));
    seg.update(cur_comp+1, seg.query(0, cur_comp));
  }
  mint res;
  for (int i = 0; i < (int)size(compress); i++) res += seg.query(i+1);
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
