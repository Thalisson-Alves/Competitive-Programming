template<typename T> ll inversion_count(vector<T> &v, int l, int m, int r)
{
  vector<T> cv(v.begin() + l, v.begin() + r + 1);
  int a = 0, b = m+1-l, i = l;
  ll res = 0;
  while (a <= m-l and b <= r-l)
  {
    if (cv[a] > cv[b])
      v[i++] = cv[b++], res += m - a - l + 1;
    else
      v[i++] = cv[a++];
  }
  while (a <= m-l)
    v[i++] = cv[a++];
  while (b <= r-l)
    v[i++] = cv[b++];

  dbg(l, m, r, res);
  return res;
}

template<typename T> ll inversion_count(vector<T> &v, int l, int r)
{
  if (l >= r)
    return 0;

  int m = l + (r - l) / 2;
  auto left = inversion_count(v, l, m);
  auto right = inversion_count(v, m+1, r);

  return left + right + inversion_count(v, l, m, r);
}
