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
using mint = modint<998244353>;

struct UFDS {
  vector<int> ps, sz;
  int components;
  UFDS(int n = 0) : ps(n), sz(n, 1), components(n) {
    iota(ps.begin(), ps.end(), 0);
  }
  int find(int x) { return (x == ps[x] ? x : (ps[x] = find(ps[x]))); }
  bool same(int x, int y) { return find(x) == find(y); }
  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    ps[y] = x;
    sz[x] += sz[y];
    --components;
    return true;
  }
  int add() {
    int id = (int)ps.size();
    ps.push_back(id);
    sz.push_back(1);
    ++components;
    return id;
  };
};

vector<int> inversion_order_tree(const vector<int> &ps, const vector<pair<int, int>> &v) {
  using T = tuple<ll, ll, int>;
  constexpr auto comp = [](const T &a, const T &b) {
    return get<0>(a)*get<1>(b) < get<0>(b)*get<1>(a);
  };
  priority_queue<T, vector<T>, decltype(comp)> pq(comp);
  int root = -1;
  vector<int> f(size(ps), -1), first(size(ps)), last(size(ps));
  vector<pair<ll, ll>> val(size(ps));
  for (int i = 0; i < (int)size(ps); i++) {
    if (~ps[i]) pq.emplace(v[i].first, v[i].second, i);
    else root = i;
    first[i] = last[i] = i;
    val[i] = v[i];
  }
  UFDS ufds((int)size(ps));
  while (size(pq)) {
    auto [zeros, ones, i] = pq.top();
    pq.pop();
    int p = ufds.find(ps[i]);
    i = ufds.find(i);
    if (!ufds.join(i, p)) continue;
    int x = ufds.find(i);
    f[last[p]] = first[i];
    first[x] = first[p];
    last[x] = last[i];
    val[x] = {val[i].first + val[p].first, val[i].second + val[p].second};
    if (~ps[first[x]]) pq.emplace(val[x].first, val[x].second, first[x]);
  }
  vector<int> res;
  for (; ~root; root = f[root]) res.push_back(root);
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &x : p) cin >> x;
  p.insert(begin(p), -1);
  vector<pair<int, int>> a(n);
  ll total = 0;
  for (auto &x : a) cin >> x.first, x.second = 1, total += x.first;
  a.insert(begin(a), {0, 1});
  auto perm = inversion_order_tree(p, a);
  mint res;
  for (int i = 0; i <= n; i++) res += i * a[perm[i]].first;
  cout << res / total << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
