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

auto dijkstra(const vector<vector<pair<int, ll>>> &g, int s)
{
  vector<ll> min_cost(g.size(), LLONG_MAX);
  min_cost[s] = 0;

  using T = pair<ll, int>;
  priority_queue<T, vector<T>, greater<T>> pq;
  pq.emplace(0, s);

  while (not pq.empty())
  {
    auto [cost, cur] = pq.top(); pq.pop();
    if (cost != min_cost[cur]) continue;

    for (auto [x, y] : g[cur])
    {
      auto new_cost = min_cost[cur] + y;

      if (new_cost < min_cost[x])
      {
        min_cost[x] = new_cost;
        pq.emplace(new_cost, x);
      }
    }
  }

  return min_cost;
}

mint dp(const vector<vector<pair<int, ll>>> &g, int s, ll w, map<pair<int, ll>, mint> &memo, const vector<ll> &min_cost)
{
  if (w < min_cost[s]) return 0;
  auto it = memo.find(make_pair(s, w));
  if (it != memo.end()) return it->second;

  mint ans = 0;
  for (auto [x, y] : g[s])
    ans += dp(g, x, w-y, memo, min_cost);

  return memo[make_pair(s, w)] = ans;
}

template <const ll INF = INT_MAX>
ll best_path(const vector<vector<pair<int, ll>>> &g, int s, ll w, map<pair<int, ll>, ll> &memo, const vector<ll> &min_cost)
{
  auto it = memo.find(make_pair(s, w));
  if (it != memo.end()) return it->second;

  ll ans = INF;
  for (auto [x, y] : g[s])
  {
    if (w - y < min_cost[x]) continue;

    if constexpr (INF == INT_MAX)
      ans = min(ans, best_path<INF>(g, x, w-y, memo, min_cost) + 1);
    else
      ans = max(ans, best_path<INF>(g, x, w-y, memo, min_cost) + 1);
  }

  return memo[make_pair(s, w)] = ans;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> g(n), gr(n);
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    g[a-1].emplace_back(b-1, c);
    gr[b-1].emplace_back(a-1, c);
  }

  auto min_cost = dijkstra(g, 0);

  map<pair<int, ll>, mint> memo;
  memo[make_pair(0, 0)] = 1;
  auto ans = dp(gr, n-1, min_cost.back(), memo, min_cost);
  map<pair<int, ll>, ll> memo2;
  memo2[make_pair(0, 0)] = 0;
  auto min_path = best_path(gr, n-1, min_cost.back(), memo2, min_cost);
  dbg(memo2);
  memo2.clear();
  memo2[make_pair(0, 0)] = 0;
  auto max_path = best_path<INT_MIN>(gr, n-1, min_cost.back(), memo2, min_cost);
  dbg(memo2);

  cout << min_cost.back() << ' ' << ans << ' ' << min_path << ' ' << max_path << '\n';
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
 
