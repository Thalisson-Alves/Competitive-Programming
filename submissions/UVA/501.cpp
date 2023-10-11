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
  int m, n;
  cin >> m >> n;
  vector<ll> v(m), u(n);
  for (auto &x : v) cin >> x;
  for (auto &x : u) cin >> x;

  int cur = 0;
  map<ll, ll> mp;
  pair<ll, ll> ans = {LLONG_MAX, 1};
  bool duty = false;

  for (int i = 0; i < n; i++)
  {
    for (; cur < u[i]; cur++)
    {
      auto it = mp.insert({v[cur], 0}).first;
      assert(it != mp.end());
      it->second++;

      if (duty)
      {
        if (it->first >= ans.first and mp[ans.first] == ans.second)
          ans = {mp.upper_bound(ans.first)->first, 1};
        else if (it->first >= ans.first)
          ans.second++;
        duty = false;

        continue;
      }

      if (it->first < ans.first)
        ans.second--;

      if (not ans.second)
      {
        assert(mp.lower_bound(ans.first) != mp.begin());
        ans = *prev(mp.lower_bound(ans.first));
      }
    }
    if (duty)
    {
      if (mp[ans.first] == ans.second)
        ans = {mp.upper_bound(ans.first)->first, 1};
      else
        ans.second++;
    }

    duty = true;
    cout << ans.first << '\n';
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  for (auto i = 1; i <= t; i++)
  {
    solve();
    if (i < t) cout << '\n';
  }

  return 0;
}

