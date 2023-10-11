#include <bits/stdc++.h>
#include <memory>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

void solve()
{
  int n, h, w;
  cin >> n >> h >> w;
  for (int i = 0; i < n; i++)
  {
    char f, s; cin >> f >> s;
    if (f == 'Y' or not w)
    {
      cout << "Y ";
      h--;
      w++;
    }
    else {
      cout << "N ";
    }

    if (s == 'Y' or not h)
    {
      cout << "Y\n";
      w--;
      h++;
    }
    else {
      cout << "N\n";
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

