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
ll oo = 1e18;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

ll MAX_N = 1e6;
vector<char> is_prime(MAX_N+1, true);
vector<int> primes;
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
  int l, u;
  cin >> l >> u;

  map<int, int> mp;
  int prev = 0;
  for (auto it = lower_bound(all(primes), l); it != primes.end() and *it <= u; it++)
  {
    if (prev)
      mp[*it - prev]++;
    prev = *it;
  }

  dbg(mp);

  int ans = 0, ansc = 0;
  for (auto it = mp.begin(); it != mp.end(); it++)
    if (it->second > ansc)
    {
      ans = it->first;
      ansc = it->second;
    }
    else if (it->second == ansc)
      ans = 0;

  if (ans)
    cout << "The jumping champion is " << ans << '\n';
  else
    cout << "No jumping champion\n";
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

