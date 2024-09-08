template <typename T> T comb_dp(T n, T k) {
  if (k > n) return (T)0;
  static vector<vector<T>> dp = {{1}};
  while ((T)dp.size() <= n) {
    auto &cur = dp.emplace_back(dp.back().size() + 1, 1);
    const auto &prev = dp[dp.size() - 2];
    for (int i = 1; i < (int)prev.size(); i++)
      cur[i] = prev[i-1] + prev[i];
  }
  return dp[n][k];
}
