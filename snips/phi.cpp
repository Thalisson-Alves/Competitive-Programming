ll phi(ll n)
{
  ll res = n;
  for (auto [x, _] : factors(n))
  {
    res /= x;
    res *= (x - 1);
  }
  return res;
}
