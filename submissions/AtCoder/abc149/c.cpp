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

bool is_prime(ll x)
{
  for (ll i = 2; i*i <= x; i++)
    if (x % i == 0)
      return false;
  return x > 1;
}

void solve()
{
  ll x;
  cin >> x;
  for (; not is_prime(x); x++);
  cout << x << '\n';
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

