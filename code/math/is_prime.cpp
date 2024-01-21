bool is_prime(ll x)
{
  for (ll i = 2; i*i <= x; i++)
    if (x % i == 0)
      return false;
  return x > 1;
}
