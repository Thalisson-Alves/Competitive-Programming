#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

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
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (auto &x : g) sort(all(x));

  auto is_valid = [&g](int mask) {
    for (int i = 0; i < (int)g.size(); i++) if (mask & (1 << i)) {
      for (int j = 0; j < (int)g.size(); j++)
        if (j != i and (mask & (1 << j)) and not binary_search(all(g[i]), j))
          return false;
    }
    return true;
  };

  basic_string<bool> valid(1<<n, 0);
  for (int mask = 1; mask < (1ll << n); mask++) {
    valid[mask] = is_valid(mask);
  }

  vector<ll> memo(1<<n, INT_MAX);
  y_combinator([&valid, &memo](auto&&dp, int mask) -> ll {
    if (!mask) return 0;
    auto &res = memo[mask];
    if (res != INT_MAX) return res;
    for (int sub = mask; sub; sub = (sub-1)&mask)
      if (valid[sub])
        res = min(res, dp(mask&~sub) + 1);
    return res;
  })((1<<n)-1);

  cout << memo.back() << '\n';
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
