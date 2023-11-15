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

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<map<int, int>> a(n+1);
  map<int, set<int>> b;
  while (q--)
  {
    int t, x;
    cin >> t >> x;
    if (t == 1)
    {
      int y;
      cin >> y;

      a[y][x]++;
      b[x].insert(y);
    }
    else if (t == 2)
    {
      bool first = true;
      for (auto [e, f] : a[x])
      {
        while (f--)
        {
          if (not first) cout << ' ';
          cout << e;
          first = false;
        }
      }
      cout << '\n';
    }
    else
    {
      dbg(b);
      bool first = true;
      for (auto e : b[x])
      {
        if (not first) cout << ' ';
        cout << e;
        first = false;
      }
      cout << '\n';
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

