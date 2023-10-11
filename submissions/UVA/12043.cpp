#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

ll MAX_N = 1e6;
vector<char> is_prime(MAX_N+1, true), is_prime_square(MAX_N+1, false);
vector<ll> primes;
void sieve()
{
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= MAX_N; i++)
  {
    if (not is_prime[i]) continue;
    if (i*i <= MAX_N)
      is_prime_square[i*i] = true;
    primes.push_back(i);
    for (ll j = i * i; j <= MAX_N; j+=i)
      is_prime[j] = false;
  }
}

ll fpow(ll x, ll p)
{
  if (p == 0) return 1;
  auto ans = fpow(x, p >> 1);
  ans *= ans;
  if (p & 1) ans *= x;
  return ans;
}

pair<ll, ll> divisors_and_sum(ll n)
{
  ll divs = 1, divs_sum = 1;
  int i = 0;
  for (i = 0;; i++)
  {
    auto p = primes[i];
    if (p*p*p > n) break;

    int count = 1;
    while (n % p == 0)
    {
      n /= p;
      count++;
    }

    divs *= count;
    divs_sum *= (fpow(p, count) - 1) / (p - 1);
  }

  if (is_prime[n])
  {
    divs *= 2;
    divs_sum *= n+1;
  }
  else if (is_prime_square[n])
  {
    divs *= 3;

    ll x = sqrt(n);
    divs_sum *= x*x+x+1;
  }
  else if (n != 1)
  {
    divs *= 4;

    for (; primes[i]*primes[i] <= n; i++) if (n%primes[i] == 0) break;
    divs_sum *= primes[i] + 1;
    divs_sum *= n/primes[i] + 1;
  }

  return {divs, divs_sum};
}

vector<pair<ll, ll>> memo(1e5+10);

void solve()
{
  ll a, b, k;
  cin >> a >> b >> k;

  ll x = 0, y = 0;
  for (ll i = a - (a % k) + (a%k ? k : 0); i <= b; i += k)
  {
    if (not memo[i].first and not memo[i].second)
      memo[i] = divisors_and_sum(i);

    x += memo[i].first;
    y += memo[i].second;
  }

  cout << x << ' ' << y << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  sieve();
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
 
