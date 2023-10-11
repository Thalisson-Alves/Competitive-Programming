#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'
#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<ll, ll>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0, x; i < n; i++)
    cin >> x, a[x-1] = i;
  for (int i = 0, x; i < n; i++)
    cin >> x, b[x-1] = i;

  vector<ii> p(n);
  for (int i = 0; i < n; i++)
    p[i] = {min(a[i], b[i]), max(a[i], b[i])};

#define intersects(x, p) (p.first <= x and x <= p.second)
  ii pref = p[0];
#define calc(x) ((x) * ((x) - 1) / 2)
  ll ans = n - 1 + calc(pref.first) + calc(n - pref.second - 1) + calc(pref.second - pref.first - 1);
  for (int i = 0; i < n-1; i++)
  {
    pref = {min(pref.first, p[i].first), max(pref.second, p[i].second)};
    if (intersects(p[i+1].first, pref) or intersects(p[i+1].second, pref))
      continue;

    if (pref.second < p[i+1].first)
      ans += (pref.first + 1) * (p[i+1].first - pref.second);
    else if (p[i+1].second < pref.first)
      ans += (n - pref.second) * (pref.first - p[i+1].second);
    else
      ans += (pref.first - p[i+1].first) * (p[i+1].second - pref.second);
  }
  cout << ans << '\n';
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
