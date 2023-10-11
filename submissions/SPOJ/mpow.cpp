#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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
  static_assert(mod < static_cast<u64>(1) << 32,
                "Modulus must be less than 2**32");

  u64 v;

  constexpr modint &negate() noexcept {
    if (v != 0)
      v = mod - v;
    return *this;
  }

public:
  constexpr modint(const u64 x = 0) noexcept : v(x % mod) {}
  constexpr u64 &value() noexcept { return v; }
  constexpr const u64 &value() const noexcept { return v; }
  constexpr modint operator+() const noexcept { return modint(*this); }
  constexpr modint operator-() const noexcept { return modint(*this).negate(); }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    v += rhs.v;
    if (v >= mod)
      v -= mod;
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (v < rhs.v)
      v += mod;
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
      if (exp % 2 != 0)
        *this *= rhs;
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
  constexpr modint pow(u64 x)
  {
    if (x == 0) return 1;
    auto ans = pow(x/2);
    ans *= ans;
    if (x&1) ans *= x;
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
using matrix_t = vector<vector<mint>>;

matrix_t &operator+=(matrix_t &a, const matrix_t &b)
{
  for (int i = 0; i < (int)b.size(); i++)
    for (int j = 0; j < (int)b[i].size(); j++)
      a[i][j] += b[i][j];
  return a;
}

matrix_t operator+(const matrix_t &a, const matrix_t &b)
{
  auto res = a;
  res += b;
  return res;
}

matrix_t &operator-=(matrix_t &a, const matrix_t &b)
{
  for (int i = 0; i < (int)b.size(); i++)
    for (int j = 0; j < (int)b[i].size(); j++)
      a[i][j] -= b[i][j];
  return a;
}

matrix_t operator-(const matrix_t &a, const matrix_t &b)
{
  auto res = a;
  res -= b;
  return res;
}

matrix_t &operator*=(matrix_t &a, const matrix_t &b)
{
  if (a.size() == 1)
  {
    a[0][0] *= b[0][0];
    return a;
  }

  int split = (int)a.size() >> 1;
  matrix_t a11(split, vector<mint>(split));
  matrix_t a12(split, vector<mint>(split));
  matrix_t a21(split, vector<mint>(split));
  matrix_t a22(split, vector<mint>(split));

  matrix_t b11(split, vector<mint>(split));
  matrix_t b12(split, vector<mint>(split));
  matrix_t b21(split, vector<mint>(split));
  matrix_t b22(split, vector<mint>(split));

  for (int i = 0; i < split; i++)
  {
    for (int j = 0; j < split; j++)
    {
      a11[i][j] = a[i][j];
      a12[i][j] = a[i][j+split];
      a21[i][j] = a[i+split][j];
      a22[i][j] = a[i+split][j+split];

      b11[i][j] = b[i][j];
      b12[i][j] = b[i][j+split];
      b21[i][j] = b[i+split][j];
      b22[i][j] = b[i+split][j+split];
    }
  }

  auto m1 = a11;
  m1 += a22;
  m1 *= b11 + b22;
  auto m2 = a21;
  m2 += a22;
  m2 *= b11;
  auto m3 = a11;
  m3 *= b12 - b22;
  auto m4 = a22;
  m4 *= b21 - b11;
  auto m5 = a11;
  m5 += a12;
  m5 *= b22;
  auto m6 = a21;
  m6 -= a11;
  m6 *= b11 + b12;
  auto m7 = a12;
  m7 -= a22;
  m7 *= b21 + b22;

  auto res11 = m1;
  res11 += m4;
  res11 -= m5;
  res11 += m7;
  auto res12 = m3;
  res12 += m5;
  auto res21 = m2;
  res21 += m4;
  auto res22 = m1;
  res22 -= m2;
  res22 += m3;
  res22 += m6;

  for (int i = 0; i < split; i++)
  {
    for (int j = 0; j < split; j++)
    {
      a[i][j] = res11[i][j];
      a[i][j+split] = res12[i][j];
      a[i+split][j] = res21[i][j];
      a[i+split][j+split] = res22[i][j];
    }
  }

  return a;
}

matrix_t operator*(const matrix_t &a, const matrix_t &b)
{
  // auto res = a;
  // res *= b;
  // return res;

  auto res = a;
  for (int i = 0; i < (int)a.size(); i++)
  {
    for (int j = 0; j < (int)a.size(); j++)
    {
      res[i][j] = 0;
      for (int k = 0; k < (int)a.size(); k++)
        res[i][j] += a[i][k] * b[k][j];
    }
  }
  return res;
}

matrix_t identity(size_t n)
{
  matrix_t res(n, vector<mint>(n));
  for (size_t i = 0; i < n; i++)
    res[i][i] = 1;
  return res;
}

template<typename T>
T fpow(T x, ll p)
{
  if (p == 0) return identity(x.size());
  auto ans = fpow(x, p >> 1);
  ans = ans * ans;
  // ans *= ans;
  // if (p & 1) ans *= x;
  if (p & 1) ans = ans * x;
  return ans;
}

ll next_power(ll x)
{
  x--;
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  x |= x >> 32;
  x++;
  return x;
}

void solve()
{
  ll n, m;
  cin >> n >> m;

  ll dim = next_power(n);
  dbg(dim);

  matrix_t a(n, vector<mint>(n));
  for (auto &row : a)
  {
    for (auto &x : row) cin >> x;
    row.resize(dim);
  }
  a.resize(dim, vector<mint>(dim));

  auto res = fpow(a, m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cout << res[i][j] << " \n"[j == n-1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
 
