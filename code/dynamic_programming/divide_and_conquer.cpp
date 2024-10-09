/* Divide and Conquer DP Optimization
 *
 * Parameters:
 * - n: number of elements
 * - k: number of iterations
 * - f: function to calculate cost
 *   - must satisfy quadrangle inequality:
 *     f(a, c) + f(b, d) <= f(a, d) + f(b, c) for a <= b <= c <= d
 *
 * Time complexity: O(n * k * log(n))
 */
template <typename T, T inf = numeric_limits<T>::max()>
T divide_and_conquer(int n, int k, auto &&f) {
  auto cmp = []() {
    if constexpr (inf == numeric_limits<T>::max()) return greater<>();
    else return less<>();
  }();
  vector<T> dp(n), next_dp(n);
  for (int i = 0; i < n; i++) dp[i] = f(0, i);
  auto calc = [&](auto &&self, int l, int r, int x, int y) -> void {
    if (l > r) return;
    int m = midpoint(l, r);
    pair<T, int> best = {inf, -1};
    for (int i = x; i <= min(y, m); i++) {
      auto value = (i ? dp[i-1] : 0) + f(i, m);
      if (cmp(best.first, value)) best = {value, i};
    }
    next_dp[m] = best.first;
    self(self, l, m-1, x, best.second);
    self(self, m+1, r, best.second, y);
  };
  while (--k) {
    calc(calc, 0, n-1, 0, n-1);
    swap(dp, next_dp);
  }
  return dp[n-1];
}
