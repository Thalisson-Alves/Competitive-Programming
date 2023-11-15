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
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  ll n, m;
  cin >> n >> m;
  ll value = 1, cnt = -1;
  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    x /= 2;
    if (value / gcd(value, x) > m / x)
    {
      cout << "0\n";
      return;
    }
    value = lcm(value, x);

    ll d2 = 1;
    while (x % 2 == 0)
    {
      x /= 2;
      d2 *= 2;
    }
    if (cnt == -1)
      cnt = d2;
    else if (cnt != d2)
    {
      cout << "0\n";
      return;
    }
  }
  assert(value <= m);
  dbg(value);

  cout << (m / value + 1) / 2 << '\n';
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
 
