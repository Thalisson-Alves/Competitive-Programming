#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

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
  int n, c, t1, t2;
  cin >> n >> c >> t1 >> t2;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<int> dist(n);
  for (int i = 0; i < n-1; i++) {
    dist[i] = a[i+1] - a[i];
  }
  dist.back() = c - a.back() + a.front();

  vector<int> dp(n, INT_MAX);
  y_combinator([&](auto &&dfs, int cur, int covered) -> int {
    if (covered >= 0 and cur == n-1) return 0;
    if (covered >= 0) return dfs((cur+1)%n, covered-dist[cur]);
    auto &memo = dp[cur];
    if (memo != INT_MAX) return memo;
    if (cur == n-1) return memo = min(t1, t2);

    memo = min(memo, dfs((cur+1)%n, t1-dist[cur]) + t1);
    memo = min(memo, dfs((cur+1)%n, t2-dist[cur]) + t2);
    return memo;
  })(0, -1);

  cout << dp[0] << '\n';
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
