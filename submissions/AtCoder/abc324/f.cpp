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

constexpr double EPS = 1e-10;

double dfs(const vector<vector<array<int, 3>>> &g, int u, const double k, vector<double> &memo) {
  if (fabs(memo[u]) >= EPS) return memo[u];
  if (u == (int)g.size() - 1) return 0.0;
  double best = -1e10;
  for (auto &x : g[u]) {
    auto value = dfs(g, x[0], k, memo) + x[1] - x[2] * k;
    if (best < value) {
      best = value;
    }
  }

  return memo[u] = best;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<array<int, 3>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, b, c;
    cin >> u >> v >> b >> c;
    g[u-1].push_back({v-1, b, c});
  }

  vector<double> memo(n);
  auto f = [&](double k) -> double {
    memo.assign(n, 0.0);
    return dfs(g, 0, k, memo);
  };

  double l = 0.0, r = 1e10;
  while ((r - l) > EPS) {
    auto mid = (l + r) / 2.0;
    if (f(mid) > EPS) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << fixed << setprecision(9) << l << '\n';
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
