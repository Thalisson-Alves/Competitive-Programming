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

pair<ll, ll> pos(ll n)
{
  ll x = 0, y = 0, willi = 0;
  for (ll d = 4; willi + d < n; willi += d, d += 4, x--);

  while (willi < n)
  {
    y++;
    willi++;
    for (; willi < n and x; willi++, y++, x++);
    for (; willi < n and y; willi++, y--, x++);
    for (; willi < n and x; willi++, y--, x--);
    for (; willi < n and y; willi++, y++, x--);
  }

  return {x, y};
}

void solve()
{
  for (ll a, b; cin >> a >> b, a >= 0;)
  {
    auto pa = pos(a);
    auto pb = pos(b);

    dbg(a, pa);
    dbg(b, pb);

    cout << fixed << setprecision(2) << hypot(pa.first - pb.first, pa.second - pb.second) << '\n';
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

