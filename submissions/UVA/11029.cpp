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
  ll n, k;
  cin >> n >> k;
  auto x = k * log10(n);
  ll first = (ll)(pow(10ll, x-(ll)x) * 100);
  cout << setfill('0') << setw(3) << first << "..." << setfill('0') << setw(3) << fpow(n, k, 1000) << '\n';;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}

