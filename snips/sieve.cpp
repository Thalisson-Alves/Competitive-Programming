ll MAX_N = 1e6;
vector<char> is_prime(MAX_N+1, true);
void sieve()
{
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= MAX_N; i++)
  {
    if (not is_prime[i]) continue;
    for (ll j = i * i; j <= MAX_N; j+=i)
      is_prime[j] = false;
  }
}
