int edit_distance(const string &a, const string &b)
{
  const auto c_i = 1, c_r = 1, c_u = 1;
  vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));

  for (int i = 0; i <= (int)a.size(); i++)
    dp[i][0] = i*c_r;

  for (int i = 1; i <= (int)b.size(); i++)
    dp[0][i] = i*c_i;

  for (int i = 1; i <= (int)a.size(); i++)
    for (int j = 1; j <= (int)b.size(); j++)
      dp[i][j] = min({dp[i-1][j-1] + (a[i-1] != b[j-1] ? c_u : 0),
                      dp[i][j-1] + c_i,
                      dp[i-1][j] + c_r});
  return dp.back().back();
}
