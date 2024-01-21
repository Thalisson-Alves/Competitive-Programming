int lis(const vector<int> &v)
{
  vector<int> res;
  for (auto x : v)
  {
    auto it = lower_bound(all(res), x);
    if (it == res.end())
      res.push_back(x);
    else
      *it = x;
  }
  return (int)res.size();
}
