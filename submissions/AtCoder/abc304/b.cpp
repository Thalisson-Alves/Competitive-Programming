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

void solve()
{
  ll n;
  cin >> n;

  if (n<1e3)
    cout << n << '\n';
  else if (n<1e4)
    cout << n - n%10 << '\n';
  else if (n<1e5)
    cout << n - n%100 << '\n';
  else if (n<1e6)
    cout << n - n%1000 << '\n';
  else if (n<1e7)
    cout << n - n%10000 << '\n';
  else if (n<1e8)
    cout << n - n%100000 << '\n';
  else if (n<1e9)
    cout << n - n%1000000 << '\n';
  else cout << n << '\n';
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

