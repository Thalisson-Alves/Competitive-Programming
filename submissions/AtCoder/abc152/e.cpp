#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

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
  constexpr modint(const u64 x = 0) noexcept : v(x % mod) {}
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
  constexpr modint pow(u64 x) const
  {
    if (x == 0) return 1;
    auto ans = pow(x>>1);
    ans *= ans;
    if (x&1) ans *= v;
    return ans;
  }

  friend ostream& operator<<(ostream& s, const modint<mod>& x)
  {
    s << x.value();
    return s;
  }

  friend istream& operator>>(istream& s, modint<mod>& x)
  {
    s >> x.v;
    return s;
  }
};

template <uint_fast64_t Modulus>
constexpr typename modint<Modulus>::u64 modint<Modulus>::mod;
using mint = modint<1000000007>;

map<ll, ll> factors(ll n)
{
  map<ll, ll> ans;
  for (ll i = 2; i*i <= n; i++)
  {
    ll count = 0;
    for (; n%i==0; count++, n/=i);
    if (count)
      ans[i] = count;
  }
  if (n > 1) ans[n]++;
  return ans;
}

map<ll, ll> slow_lcm(const vector<ll> &a)
{
  map<ll, ll> ans;
  for (auto x : a)
  {
    auto f = factors(x);
    for (auto [k, v] : f)
      ans[k] = max(ans[k], v);
  }
  return ans;
}

void solve()
{
  int n;
  cin >> n;

  vector<ll> a(n);
  for (auto &x : a) cin >> x;

  auto lcm = slow_lcm(a);

  mint ans = 0;
  for (auto x : a)
  {
    auto f = factors(x);

    mint value = 1;
    for (auto [k, v] : f)
      value *= mint(k).pow(lcm[k] - v);
    for (auto [k, v] : lcm)
      if (not f.count(k))
        value *= mint(k).pow(v);

    ans += value;
  }

  cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
 
