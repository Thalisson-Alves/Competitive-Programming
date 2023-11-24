#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

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

vector<int> tree_diameter(const vector<vector<int>> &g)
{
  vector<int> dist(g.size(), -1);
  int last = 0;
  dist[last] = 0;
  tree_diameter(g, last, dist, last);

  dist.assign(g.size(), -1);
  dist[last] = 0;
  tree_diameter(g, last, dist, last);

  return dist;
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  auto dist = tree_diameter(g);
  auto diameter = *max_element(all(dist));
  int a = -1;
  for (int i = 0; i < n; i++) {
    if (dist[i] != diameter) continue;
    if (a == -1) a = i;
  }
  vector<int> da(g.size(), -1);
  {
    int last = a;
    da[last] = 0;
    tree_diameter(g, a, da, last);
  }

  for (int i = 0; i < n; i++) {
    cout << max({diameter, da[i]+1, dist[i]+1}) << '\n';
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
