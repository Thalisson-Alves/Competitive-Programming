/* Knuth DP Optimization
 *
 * Usually used in problems that one need to minimize/maximize
 * the cost of spliting/merging subarrays.
 *
 * Parameters:
 * - n: number of elements
 * - f: cost function of range [i, j]
 *   - must satisfy quadrangle inequality:
 *     f(a, c) + f(b, d) <= f(a, d) + f(b, c) for a <= b <= c <= d
 * - def: default value for dp[i][i]
 *
 * Time complexity: O(n^2)
 */
template <typename T, T inf = numeric_limits<T>::max()>
T knuth_optimization(int n, auto f, T def=T()) {
  vector<vector<ll>> dp(n, vector<ll>(n, def));
  vector<vector<int>> opt(n, vector<int>(n));
  for (int i = 0; i < n; i++) opt[i][i] = i;
  auto cmp = []() {
    if constexpr (inf == numeric_limits<T>::max()) return greater<T>();
    else return less<T>();
  }();
  for (int i = n-2; ~i; --i) {
    for (int j = i+1; j < n; j++) {
      ll res = inf;
      ll cost = f(i, j);
      for (int k = opt[i][j-1]; k <= min(j-1, opt[i+1][j]); k++) {
        if (cmp(res, dp[i][k] + dp[k+1][j] + cost)) {
          res = dp[i][k] + dp[k+1][j] + cost;
          opt[i][j] = k;
        }
      }
      dp[i][j] = res;
    }
  }
  return dp[0][n-1];
}
