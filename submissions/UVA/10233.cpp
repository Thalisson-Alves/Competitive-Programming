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

pair<ll, ll> triangle(ll x)
{
  ll depth = 0, middle = 0;
  for (; middle + depth < x; middle += 2 * depth + 2, depth++);
  return {depth, x - middle};
}

pair<double, double> pos(ll x)
{
  const double H = sqrt(3) / 2.0;
  const double B = H / 3.0;

  auto t = triangle(x);
  double y = t.first * H + ((t.first + t.second) & 1 ? B : H - B);

  return {0.5 * t.second, y};
}

void solve()
{
  for (ll a, b; cin >> a >> b;)
  {
    auto pa = pos(a);
    auto pb = pos(b);

    auto ans = hypot(pa.first - pb.first, pa.second - pb.second);
    cout << fixed << setprecision(3) << ans << '\n';
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

