#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

set<ll> primes;
void factors(ll &x)
{
  for (ll i = (primes.empty() ? 2 : *primes.rbegin() + 1); i*i <= x; i++)
  {
    if (x%i) continue;
    while (x%i==0) x/=i;
    primes.insert(i);
    return;
  }
  if (x > 1) primes.insert(x);
}

ll fpow(ll x, ll p, ll mod=1e9+7)
{
  if (p == 0) return 1;
  auto ans = fpow(x, p >> 1, mod);
  ans = ans * ans % mod;
  if (p & 1) ans = ans * x % mod;
  return ans;
}

void solve()
{
  ll n, m, k;
  cin >> m >> n >> k;

  vector<ll> v(n);
  for (auto &x : v) cin >> x;

  vector<tuple<ll, ll, ll>> edges(k);
	for (auto &[a, b, c] : edges) cin >> a >> b >> c, a--, b--;
	sort(all(edges));

  ll prev = -1;
  for (auto [a, b, c] : edges)
  {
    if (a == prev)
      v[b] /= fpow(*primes.rbegin(), c);
    else
      factors(v[b]);

    prev = a;
  }

  for (auto x : primes)
    cout << x << " ";
  cout << '\n';
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}

