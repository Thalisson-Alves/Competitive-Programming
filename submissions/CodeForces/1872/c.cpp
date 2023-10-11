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
  int l, r;
  cin >> l >> r;
  if (r <= 3)
  {
    cout << "-1\n";
    return;
  }

  if (l != r or l%2 == 0)
  {
    cout << "2 " << ((r-2)-(r&1)) << '\n';
    return;
  }

  for (int i = 3; i*i <= r; i++)
  {
    int comp = r - i;
    if (gcd(comp, i) != 1)
    {
      cout << i << ' ' << r-i << '\n';
      return;
    }
  }
  cout << "-1\n";
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
