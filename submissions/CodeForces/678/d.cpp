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
ll oo = 1e18;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

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
  friend istream& operator<<(istream& s, const modint<mod>& x)
  {
    s >> x.value();
    return s;
  }
};

template <uint_fast64_t Modulus>
constexpr typename modint<Modulus>::u64 modint<Modulus>::mod;
using mint = modint<1000000007>;

void solve()
{
  ll a, b, n, x;
  cin >> a >> b >> n >> x;
  // PG or PA
  auto sum = (a == 1 ? (mint(a) * n) : (mint(a).pow(n) - 1) / (a - 1));
  dbg(sum);
  auto ans = mint(a).pow(n) * x + sum * b;
  cout << ans << '\n';
}

/*
A(x) + B
*/

/*
A(A(A(A(A(x) + B) + B) + B) + B) + B
A(A(A(AA(x) + AB + B) + B) + B) + B
A(A(AAA(x) + AAB + AB + B) + B) + B
A(AAAA(x) + AAAB + AAB + AB + B) + B
AAAAA(x) + AAAAB + AAAB + AAB + AB + B

AAAAA(x) + (AAAA + AAA + AA + A + 1)B
*/

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

