ll divisors(ll n)
{
  ll ans = 1;
  for (ll i = 2; i*i <= n; i++)
  {
    ll count = 0;
    for (; n%i==0; count++, n/=i);
    if (count)
      ans *= count + 1;
  }
  if (n > 1) ans <<= 1;
  return ans;
}
