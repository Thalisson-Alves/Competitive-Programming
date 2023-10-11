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
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  sort(all(v));
  ll ans = 0, mx = 2*v[0];
  for (auto x : v)
  {
    if (x < mx) continue;
    ll l = 2, r = x;
    while (l <= r)
    {
      ll mid = (l + r) / 2;
      if (x / mid + ((x % mid) != 0) >= mx)
        l = mid + 1;
      else
        r = mid - 1;
    }
    ans += r;
  }
  cout << ans << '\n';
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

