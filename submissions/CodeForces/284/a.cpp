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

long long fpow(long long x, long long p, long long mod)
{
  if (p == 0) return 1;
  auto ans = fpow(x, p >> 1, mod);
  ans = ans * ans % mod;
  if (p & 1) ans = ans * x % mod;
  return ans;
}

void solve()
{
  ll n;
  cin >> n;

  ll ans = 0;
  for (ll x = 1; x < n; x++)
  {
    if (fpow(x, n-1, n) != 1)
      continue;

    bool ok = true;
    for (ll p = 1; ok and p < n - 1; p++)
    {
      if (fpow(x, p, n) == 1)
        ok = false;
    }

    ans += ok;
  }

  cout << ans << '\n';
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
 
