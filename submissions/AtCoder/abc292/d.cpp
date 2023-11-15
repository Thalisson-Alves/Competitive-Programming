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

void dfs(const vector<vector<ll>> &g, ll s, vector<int> &vis)
{
  for (auto x : g[s])
  {
    if (vis[x] == -1)
    {
      vis[x] = vis[s];
      dfs(g, x, vis);
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
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> vis(n, -1);
  for (int i = 0; i < n; i++)
    if (vis[i] == -1)
    {
      vis[i] = i;
      dfs(g, i, vis);
    }

  vector<pair<ll, ll>> mp(n);
  for (int i = 0; i < n; i++)
    mp[vis[i]].first++, mp[vis[i]].second += (ll)g[i].size();

  string ans = "Yes";
  for (auto [x, y] : mp)
    if (x != y / 2)
      ans = "No";
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

