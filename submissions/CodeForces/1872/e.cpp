#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
#define int ll
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  int n;
  cin >> n;
  vector<int> ps(n+1);
  for (int i =0 ; i< n; i++)
  {
    int x;
    cin >> x;
    ps[i+1] = ps[i] ^ x;
  }
  string s;
  cin >> s;
  int x1 = 0, x0 = 0;
  for (int i = 0; i < n; i++)
  {
    auto x = ps[i+1]^ps[i];
    (s[i] == '0' ? x0 ^= x : x1 ^= x);
  }

  dbg(x0, x1);
  dbg(ps);
  int q;
  cin >> q;
  while (q--)
  {
    int t, x;
    cin >> t >> x;
    if (t == 1)
    {
      int y;
      cin >> y;
      --x, --y;

      x1 ^= ps[y+1]^ps[x];
      x0 ^= ps[y+1]^ps[x];
    }
    else
    {
      cout << (x ? x1 : x0) << ' ';
    }
  }
  cout << '\n';
}

int32_t main()
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
