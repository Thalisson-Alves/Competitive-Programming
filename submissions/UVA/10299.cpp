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
  for (ll n; cin >> n, n;)
  {
    ll ans = n == 1 ? 0 : n;
    for (ll i = 2; i*i <= n; i++)
    {
      if (n%i) continue;
      ans -= ans/i;
      while (n%i == 0) n/=i;
    }

    if (n > 1)
      ans -= ans / n;
    cout << ans << '\n';
  }
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
 
