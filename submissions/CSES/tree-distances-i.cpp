#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void tree_diameter(const vector<vector<int>> &g, int s, vector<int> &dist, int &last)
{
  for (auto x : g[s])
    if (dist[x] == -1)
    {
      if ((dist[x] = dist[s] + 1) > dist[last])
        last = x;
      tree_diameter(g, x, dist, last);
    }
}

pair<vector<int>, vector<int>> tree_diameter(const vector<vector<int>> &g)
{
  vector<int> dist(g.size(), -1);
  int last = 0;
  dist[last] = 0;
  tree_diameter(g, last, dist, last);

  dist.assign(g.size(), -1);
  dist[last] = 0;
  tree_diameter(g, last, dist, last);
  auto d1 = dist;

  dist.assign(g.size(), -1);
  dist[last] = 0;
  tree_diameter(g, last, dist, last);

  return {d1, dist};
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  auto [a, b] = tree_diameter(g);
  dbg(a,b);
  for (int i = 0; i < n; i++)
    cout << max(a[i], b[i]) << ' ';
  cout << '\n';
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
