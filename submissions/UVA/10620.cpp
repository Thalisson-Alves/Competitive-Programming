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
  for (ll s, x, y, dx, dy; cin >> s >> x >> y >> dx >> dy, s;)
  {
    pair<ll, ll> ans{-1, -1};
    ll jumps = 0;
    for (jumps = 0; jumps < 1234; jumps++, x += dx, y += dy)
    {
      if (x % s == 0 or y % s == 0) continue;
      if ((x / s + y / s) & 1)
      {
        ans = {x, y};
        break;
      }
    }

    if (ans == make_pair(-1ll, -1ll))
      cout << "The flea cannot escape from black squares.\n";
    else
      cout << "After " << jumps << " jumps the flea lands at (" << ans.first << ", " << ans.second << ").\n";
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

