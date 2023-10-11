#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void topological_order(const vector<vector<int>> &g, vector<char> &vis, vector<int> &order, int s)
{
  vis[s] = true;
  for (auto x : g[s])
    if (not vis[x])
      topological_order(g, vis, order, x);
  order.push_back(s);
}

vector<int> topological_order(const vector<vector<int>> &g)
{
  vector<char> vis(g.size(), false);
  vector<int> order;
  for (auto i = 0; i < (int)g.size(); i++)
    if (not vis[i])
      topological_order(g, vis, order, i);
  reverse(order.begin(), order.end());
  return order;
}

void mark_component(const vector<vector<int>> &gr, vector<int> &component, int s)
{
  for (auto x : gr[s])
    if (component[x] == -1)
    {
      component[x] = component[s];
      mark_component(gr, component, x);
    }
}

vector<int> mark_components(const vector<vector<int>> &gr, const vector<int> &order)
{
  vector<int> components(gr.size(), -1);
  for (auto x : order)
    if (components[x] == -1)
    {
      components[x] = x;
      mark_component(gr, components, x);
    }
  return components;
}

ll max_coins(const vector<set<int>> &g, int s, const vector<ll> &coins, vector<ll> &memo)
{
  if (memo[s]) return memo[s];
 
  ll mx = 0;
  for (auto x : g[s])
    mx = max(mx, max_coins(g, x, coins, memo));
 
  return memo[s] = mx + coins[s];
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<ll> coins(n);
  for (auto &x : coins) cin >> x;
  vector<vector<int>> g(n), gr(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    gr[b].push_back(a);
  }

  auto comp = mark_components(gr, topological_order(g));
  vector<set<int>> condensed(n);
  vector<ll> condensed_coins(n);
  for (int i = 0; i < n; i++)
  {
    condensed_coins[comp[i]] += coins[i];
 
    for (auto x : g[i])
      if (comp[i] != comp[x])
        condensed[comp[i]].insert(comp[x]);
  }
 
  vector<ll> memo(n);
  ll ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, max_coins(condensed, i, condensed_coins, memo));
  cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
 
