#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

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

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &x: a) cin >> x;
  sort(all(a), [](auto x, auto y) { return abs(x) < abs(y); });
  ll ne = 0, mnpos = INT_MAX, mnneg = INT_MAX;
  mint ans = 1;
  for (int i = 0; i < k; i++) {
    ans *= abs(a[n-i-1]);
    ne ^= a[n-i-1] < 0;
    if (a[n-i-1] > 0) mnpos = min(mnpos, a[n-i-1]);
    if (a[n-i-1] < 0) mnneg = min(mnneg, abs(a[n-i-1]));
  }
  if (!ne) {
    cout << ans << '\n';
    return;
  }

  ll npos = -1, nneg = -1;
  for (int i = n-k-1; ~i; --i) {
    if (npos == -1 and a[i] >= 0) npos = a[i];
    if (nneg == -1 and a[i] < 0) nneg = -a[i];
  }

  if (mnpos == INT_MAX) {
    if (npos == -1) {
      mint res = 1;
      for (int i = 0; i < k; i++)
        res *= abs(a[i]);
      cout << mint::mod - res.value() << '\n';
    } else {
      cout << ans * npos / mnneg << '\n';
    }
  } else {
    if (nneg == -1) {
      if (npos == -1) {
        mint res = 1;
        for (int i = 0; i < k; i++)
          res *= abs(a[i]);
        cout << mint::mod - res.value() << '\n';
      } else {
        cout << ans * npos / mnneg << '\n';
      }
    } else if (npos == -1) {
      cout << ans * nneg / mnpos << '\n';
    } else {
      if (mnpos * npos > mnneg * nneg) {
        cout << ans * npos / mnneg << '\n';
      } else {
        cout << ans * nneg / mnpos << '\n';
      }
    }
  }
}

int32_t main()
{
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
