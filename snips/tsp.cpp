ll tsp(int i, int mask, const vector<vector<ll>> &dist, vector<vector<ll>> &memo)
{
  if (mask == (1 << dist.size()) - 1)
    return dist[i][0];

  if (memo[i][mask] != -1)
    return memo[i][mask];

  ll ans = oo;
  for (int j = 0; j < (int)dist.size(); j++)
  {
    if (mask & (1 << j))
      continue;

    ans = min(ans, tsp(j, mask | (1 << j), dist, memo) + dist[i][j]);
  }

  return ans;
}
