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

/*
Used to define recursive lambdas,  first argument is the function itself

auto value = y_combinator([](auto &&gcd, int a, int b) -> int {
  return b ? gcd(b, a % b) : a;
});
*/
template <class Fun> class y_combinator_result {
  Fun fun_;

  public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(n));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u][v]++;
  }

  constexpr ll mod = 1e9+7;
  vector<vector<ll>> dp(n, vector<ll>(1ll<<n, -1));
  ll res = y_combinator([&](auto &&dfs, int u, ll mask) -> ll {
    if (mask == (1ll << n) - 1 and u == n-1) return dp[u][mask] = 1;
    auto &x = dp[u][mask];
    if (x != -1) return x;
    x = 0;
    if (mask & (1ll << (n-1))) return x;
    for (int v = 0; v < n; v++) if (g[u][v] and !(mask & (1ll << v))) {
      x = (x + dfs(v, mask | (1ll << v)) * g[u][v]) % mod;
    }
    return x;
  })(0, 1ll);
  cout << res << '\n';
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
