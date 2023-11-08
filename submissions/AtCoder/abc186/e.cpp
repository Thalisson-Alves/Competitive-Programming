#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

ll fpow(ll x, ll p)
{
  if (p == 0) return 1;
  auto ans = fpow(x, p >> 1);
  ans *= ans;
  if (p & 1) ans *= x;
  return ans;
}

ll fpow(ll x, ll p, ll mod)
{
  if (p == 0) return 1;
  auto ans = fpow(x, p >> 1, mod);
  ans = ans * ans % mod;
  if (p & 1) ans = ans * x % mod;
  return ans;
}

map<ll, ll> factors(ll n)
{
  map<ll, ll> ans;
  for (ll i = 2; i*i <= n; i++)
  {
    ll count = 0;
    for (; n%i==0; count++, n/=i);
    if (count)
      ans[i] = count;
  }
  if (n > 1) ans[n]++;
  return ans;
}

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

void solve()
{
  ll n, s, k;
  cin >> n >> s >> k;

  s = n-s;
  auto d = gcd(gcd(n, s), k);
  n /= d, s /= d, k /= d;

  if (gcd(k, n) == 1) {
    cout << s * fpow(k, phi(n)-1, n) % n << '\n';
  } else {
    cout << "-1\n";
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
