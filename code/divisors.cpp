vector<ll> divisors(ll n) {
  vector<ll> d;
  for (ll i = 1; i*i <= n; i++) if (n%i == 0) {
    d.push_back(i);
    if (n/i != i) d.push_back(n/i);
  }
  return d;
}
