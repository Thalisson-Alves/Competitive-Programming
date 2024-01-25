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
  int n, k;
  cin >> n >> k;

  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    g[x-1].push_back(i);
  }

  vector<int> height(n, 1);
  y_combinator([&](auto &&dfs, int u) -> void {
    for (auto x : g[u]) {
      dfs(x);
      height[u] = max(height[u], height[x] + 1);
    }
  })(0);

  int res = 0;
  auto cmp = [&height](int a, int b) { return height[a] < height[b]; };
  priority_queue<int, vector<int>, decltype(cmp)> roots(cmp);
  roots.push(0);
  while (k-- and not roots.empty()) {
    auto u = roots.top();
    roots.pop();

    do {
      ++res;
      int mx = -1;
      for (auto x : g[u]) {
        if (mx == -1 or height[x] > height[mx]) {
          if (~mx) roots.push(mx);
          mx = x;
        } else {
          roots.push(x);
        }
      }

      u = mx;
    } while (~u);
  }

  cout << res << '\n';
}

int32_t main() {
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
