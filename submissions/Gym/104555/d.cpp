#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

#define ll int
#undef LLONG_MAX
#define LLONG_MAX INT_MAX

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

inline ll dyc(const vector<vector<pair<int, ll>>> &g, int s, int e)
{
  vector<ll> min_cost(g.size(), LLONG_MAX);
  min_cost[s] = 0;

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.emplace(0, s);

  while (not pq.empty())
  {
    auto [cost, cur] = pq.top(); pq.pop();
    if (cur == e) return min_cost[e];
    if (cost > min_cost[cur]) continue;

    for (auto [x, y] : g[cur])
    {
      if (cur == s and x == e) continue;
      if (cur == e and x == s) continue;

      auto new_cost = min_cost[cur] + y;
      if (new_cost < min_cost[x])
      {
        min_cost[x] = new_cost;
        pq.emplace(new_cost, x);
      }
    }
  }

  return -1;
}

inline void floyd_warshall(vector<vector<ll>> &d) {
  int n = static_cast<int>(d.size());
  for (int i = 0; i < n; i++)
    d[i][i] = 0;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][k] < LLONG_MAX and d[k][j] < LLONG_MAX)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}


void solve()
{
  int n, m;
  cin>> n >> m;
  vector<array<int, 3>> edges(m);
  vector<vector<pair<int, ll>>> g(n);
  vector<vector<ll>> d(n, vector<ll>(n, LLONG_MAX));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    edges[i] = {u, v, w};
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);

    d[u][v] = d[v][u] = w;
  }

  for (int i = 0; i < n; i++) {
    d[i][i] = 0;
  }

  floyd_warshall(d);

  for (auto e : edges) {
    auto u = e[0], v = e[1], w = e[2];
    if (d[u][v] < w)
      cout << d[u][v] << '\n';
    else
      cout << dyc(g, u, v) << '\n';
  }
}

int32_t main()
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
