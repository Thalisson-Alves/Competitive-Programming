#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
ll oo = 1e18;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

ll MAX_N = 55'555;
vector<char> is_prime(MAX_N+1, true);
vector<ll> primes;
void sieve()
{
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= MAX_N; i++)
  {
    if (not is_prime[i]) continue;

    primes.push_back(i);
    for (ll j = i * i; j <= MAX_N; j+=i)
      is_prime[j] = false;
  }
}

void solve()
{
  sieve();

  int n;
  cin >> n;
  vector<ll> ans(n);
  ans[0] = primes[0];
  for (int i = 1, p = 0; i < n; i++)
  {
    while (++p < (int)primes.size())
      if (primes[p]%10 == 3)
        break;

    if (p < (int)primes.size())
      ans[i] = primes[p];
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n-1];
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

