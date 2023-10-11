#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ii = pair<int, int>;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

long long fpow(long long x, long long p, long long mod=1e9+7)
{
  if (p == 0) return 1;
  auto ans = fpow(x, p >> 1, mod);
  ans = ans * ans % mod;
  if (p & 1) ans = ans * x % mod;
  return ans;
}

inline bool is_perfect(ll n)
{
  if (n == 1) return true;
  for (ll i = 2; i*i <= n; i++)
  {
    auto x = n;
    while (x % i == 0)
      x /= i;

    if (x == 1)
      return true;
  }
  return false;
}

void solve()
{
  ll n;
  cin >> n;

  for (ll i = n; i; i--)
  {
    if (is_perfect(i))
    {
      cout << i << '\n';
      return;
    }
  }
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
 
