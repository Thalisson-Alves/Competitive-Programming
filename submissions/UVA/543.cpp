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

ll MAX_N = 1e6;
vector<char> is_prime(MAX_N+1, true);
void sieve()
{
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= MAX_N; i++)
  {
    for (ll j = i * i; j <= MAX_N; j+=i)
      is_prime[j] = false;
  }
}

void solve()
{
  sieve();
  while (true)
  {
    int x; cin >> x;
    if (x == 0) break;

    int ans = 0;
    for (int i = 3; not ans; i+=2)
      if (is_prime[i] and is_prime[x-i])
        ans = i;

    cout << x << " = " << ans << " + " << x - ans << '\n';
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

