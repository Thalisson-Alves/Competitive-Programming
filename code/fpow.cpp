ll fpow(ll x, ll p) {
  ll res = 1;
  while (p) {
    if (p & 1) res *= x;
    p >>= 1;
    x *= x;
  }
  return res;
}

ll fpow(ll x, ll p, ll mod) {
  ll res = 1;
  while (p) {
    if (p & 1) res = res * x % mod;
    p >>= 1;
    x = x * x % mod;
  }
  return res;
}
