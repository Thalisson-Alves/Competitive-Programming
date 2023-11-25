constexpr pair<ll, ll> inv_gcd(ll a, ll b) {
  a %= b;
  if (a < 0) a += b;
  if (a == 0) return {b, 0};

  ll s = b, t = a;
  ll m0 = 0, m1 = 1;

  while (t) {
    ll u = s / t;
    s -= t * u;
    m0 -= m1 * u;

    swap(s, t);
    swap(m0, m1);
  }

  if (m0 < 0) m0 += b / s;
  return {s, m0};
}
