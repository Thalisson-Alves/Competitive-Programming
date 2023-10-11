#include <bits/stdc++.h>
using namespace std;

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

ll MAX_N = 1e7;
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

ll divisors(ll n)
{
  ll ans = 1;
  for (auto p : primes)
  {
    if (p*p*p > n) break;

    int count = 1;
    while (n % p == 0)
    {
      n /= p;
      count++;
    }

    ans *= count;
  }

  if (is_prime[n])
    ans *= 2;
  else if (is_prime_square[n])
    ans *= 3;
  else if (n != 1)
    ans *= 4;

  return ans;
}

void solve()
{
  sieve();
  int n;
  cin >> n;
  for (int x; cin >> x;)
    cout << divisors(x) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
 
