ll kth_fibonacci(ll k, ll mod) {
  auto rp = [&](ll a1, ll b1, ll a2, ll b2, ll c) {
    return make_pair((a1*a2%mod+b1*b2%mod*c)%mod, (a1*b2%mod+a2*b1)%mod);
  };
  auto rpm = [&](ll a, ll b, ll c) {
    ll ar = 1, br = 0;
    for (ll kk = k; kk; kk >>= 1) {
      if (kk&1) tie(ar, br) = rp(ar, br, a, b, c);
      tie(a, b) = rp(a, b, a, b, c);
    }
    return make_pair(ar, br);
  };
  auto [a1, b1] = rpm(1, 1, 5);
  auto [a2, b2] = rpm(1, mod-1, 5);
  ll a = (a1-a2+mod)%mod;
  ll b = (b1-b2+mod)%mod;
  tie(a, b) = rp(0, 1, a, b, 5);
  assert(!b);
  return a*fpow(5, mod-2, mod)%mod*fpow(fpow(2, k, mod), mod-2, mod)%mod;
}
