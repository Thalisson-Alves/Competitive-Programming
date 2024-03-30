#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

template<typename T=double> struct Point {
  T x, y;
  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}
};

/* Orientation of point `p` relative to line `a-b`
 *
 * Returns:
 * -1: `p` is to the right of the line passing through `a` and `b`
 *  0: `p` belongs to the line passing through `a` and `b`
 *  1: `p` is to the left of the line passing through `a` and `b`
 */
template<typename T> int orientation(const Point<T> &p, const Point<T> &a, const Point<T> &b) {
  auto x = a.x*(b.y-p.y)+b.x*(p.y-a.y)+p.x*(a.y-b.y);
  if (x == 0) return 0;
  return (x < 0 ? -1 : 1);
}

/* Check if point p is inside triangle v1, v2, v3 */
template <typename T> bool is_inside_triangle(const Point<T> &p, const Point<T> &v1, const Point<T> &v2, const Point<T> &v3) {
  auto o1 = orientation(p, v1, v2);
  auto o2 = orientation(p, v2, v3);
  auto o3 = orientation(p, v3, v1);

  bool neg = (o1 < 0) or (o2 < 0) or (o3 < 0);
  bool pos = (o1 > 0) or (o2 > 0) or (o3 > 0);
  return !neg or !pos;
}

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<Point<int>> points(n);
  for (auto &[x, y] : points)
    cin >> x >> y;
  sort(points.begin(), points.end(), [](const auto &p1, const auto &p2) {
    return p1.y > p2.y;
  });

  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (is_inside_triangle(points[j], {a, 0}, points[i], {b, 0}))
        g[i].push_back(j);
    }
  }

  vector<int> dp(n, -1);
  auto dfs = [&](auto &&self, int u) -> int {
    auto &memo = dp[u];
    if (~memo) return memo;
    memo = 1;
    for (auto v : g[u]) {
      memo = max(memo, self(self, v) + 1);
    }
    return memo;
  };

  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, dfs(dfs, i));
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
