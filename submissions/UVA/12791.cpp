#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n';
#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  for (int x, y; cin >> x >> y;)
  {
    int l = 2, r = 100500, ans = 0;
    while (l <= r)
    {
      int m = l + (r - l) / 2;
      int v = m * x / y - not ((m * x) % y);
      if (m - v >= 2)
      {
        ans = m;
        r = m - 1;
      }
      else
        l = m + 1;
    }
    cout << ans << '\n';
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

