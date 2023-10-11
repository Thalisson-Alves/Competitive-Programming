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
ll oo = 1e18;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

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

int tree_diameter(const vector<vector<int>> &g)
{
  vector<int> dist(g.size(), -1);
  int last = 0;
  dist[last] = 0;
  tree_diameter(g, last, dist, last);
  dbg(last, dist);

  dist.assign(g.size(), -1);
  dist[last] = 0;
  tree_diameter(g, last, dist, last);
  dbg(last, dist);

  return dist[last];
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    g[x-1].push_back(y-1);
    g[y-1].push_back(x-1);
  }

  cout << tree_diameter(g) << '\n';
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

