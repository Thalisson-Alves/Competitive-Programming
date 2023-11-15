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

void dfs(const vector<vector<ll>> &g, vector<ll> &v, ll s)
{
  for (auto x : g[s])
  {
    if (v[x] == -1)
    {
      v[x] = v[s];
      dfs(g, v, x);
    }
  }
}

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n);
  for (int i = 0; i < m; i++)
  {
    ll x, y; cin >> x >> y;
    g[--x].push_back(--y);
    g[y].push_back(x);
  }
  vector<ll> v(n, -1);
  for (int i = 0; i < n; i++)
  {
    if (v[i] == -1)
    {
      v[i] = i;
      dfs(g, v, i);
    }
  }
  map<ll, pair<ll, ll>> mp;
  for (int i = 0; i < n; i++)
  {
    auto &p = mp[v[i]];
    p.first++;
    p.second += g[i].size();
  }
  ll ans = 0;
  for (auto [_, y] : mp)
    ans += max(0ll, (ll)y.second / 2 - y.first + 1);
  cout << ans << '\n';
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

