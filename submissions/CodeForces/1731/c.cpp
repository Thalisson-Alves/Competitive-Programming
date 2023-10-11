#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'
#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  ll n;
  cin >> n;
  vector<ll> v(2*n);
  v[0]++;
  ll ans = 0;
  for (ll pref = 0, x, j = 0; j < n; j++)
  {
    cin >> x;
    pref ^= x;
    for (ll i = 0; i*i < 2*n; i++)
    {
      ll y = pref ^ (i * i);
      ans += (y < 2*n ? v[y] : 0);
    }
    v[pref]++;
  }
  cout << (n * (n + 1) / 2) - ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

