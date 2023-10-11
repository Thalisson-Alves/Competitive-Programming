#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  ll n, x, y;
  cin >> n >> x >> y;

  ll common = n/lcm(x,y);
  ll a = n / x - common;
  ll b = n / y - common;

#define sum(l,n) (n*(l+l+n-1)) / 2

  dbg(a, b);
  dbg(sum(n-a+1,a), sum(1,b));
  cout << sum(n-a+1, a) - sum(1, b) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}
