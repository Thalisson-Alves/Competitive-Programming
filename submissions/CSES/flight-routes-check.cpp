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

void dfs1(const vector<vector<int>> &g, vector<char> &vis, vector<int> &order, int s)
{
  vis[s] = true;
  for (auto x : g[s])
    if (not vis[x])
      dfs1(g, vis, order, x);
  order.push_back(s);
}

void dfs2(const vector<vector<int>> &g, vector<int> &component, int s, const int comp_value)
{
  component[s] = comp_value;
  for (auto x : g[s])
    if (component[x] == -1)
      dfs2(g, component, x, comp_value);
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n), gr(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    gr[b].push_back(a);
  }

  vector<int> order;
  vector<char> vis(n);
  for (int i = 0; i < n; i++)
    if (not vis[i])
      dfs1(g, vis, order, i);

  reverse(all(order));

  vector<int> comp(n, -1);
  pair<int, int> ans(-1, -1);
  for (auto i : order)
    if (comp[i] == -1)
    {
      dfs2(gr, comp, i, i);
      if (ans.first == -1) ans.first = i;
      else ans.second = i;
    }

  dbg(ans);
  dbg(comp);
  if (ans.second == -1)
    cout << "YES\n";
  else
  {
    cout << "NO\n";
    cout << ans.second + 1 << ' ' << ans.first + 1 << '\n';
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

