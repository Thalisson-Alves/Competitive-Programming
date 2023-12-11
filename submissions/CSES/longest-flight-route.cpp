#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[--u].push_back(--v);
  }

  vector<int> pos(n, -1);
  y_combinator([&](auto &&dfs, int u) {
    if (u == n-1) {
      pos[u] = 0;
      return;
    }
    if (~pos[u]) return;
    pos[u] = -2;
    for (auto x : g[u]) {
      dfs(x);
      if (pos[x] >= 0)
        pos[u] = max(pos[u], pos[x]+1);
    }
  })(0);

  if (pos[n-1]) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  vector<int> path;
  for (int cur = 0; cur != n-1;) {
    path.push_back(cur);
    int best = -1;
    for (auto x : g[cur]) if (pos[x] >= 0) {
      if (best == -1 or pos[best] < pos[x])
        best = x;
    }
    assert(~best);
    cur = best;
  }

  cout << path.size()+1 << '\n';
  for (auto x : path) {
    cout << x+1 << ' ';
  }
  cout << n << '\n';
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
