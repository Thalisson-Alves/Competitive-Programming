#include <algorithm>
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

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  for (ll n; cin >> n;)
  {
    ll x = 0, y = 0;
    for (ll willi = 1; willi < n;)
    {
      y++;
      willi++;
      for (; willi < n and x; willi++, y++, x--);
      for (; willi < n and -x != y; willi++, x--);
      for (; willi < n and y; willi++, y--);

      for (; willi < n and x; willi++, y--, x++);
      for (; willi < n and -x != y; willi++, x++);
      for (; willi < n and y; willi++, y++);
    }

    cout << x << ' ' << y << '\n';
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

