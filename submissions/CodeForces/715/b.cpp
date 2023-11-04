#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;

struct edge {
  int to;
  ll w;
  int id = -1;
};

vector<ll> dijkstra(const vector<vector<edge>> &g, int s, int bound=-1, int value=1)
{
  vector<ll> min_cost(g.size(), LLONG_MAX);
  min_cost[s] = 0;

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.emplace(0, s);

  while (not pq.empty())
  {
    auto [cost, cur] = pq.top(); pq.pop();
    if (cost != min_cost[cur]) continue;

    for (auto [x, y, id] : g[cur])
    {
      if (id >= 0) {
        if (id < bound) y = 1;
        else if (id == bound) y = value;
        else y = INT_MAX;
      }
      auto new_cost = min_cost[cur] + y;
      if (new_cost < min_cost[x])
      {
        min_cost[x] = new_cost;
        pq.emplace(new_cost, x);
      }
    }
  }

  return min_cost;
}
 
void solve()
{
  int n, m, L, s, t;
  cin >> n >> m >> L >> s >> t;
  vector<vector<edge>> g(n);
  {
    int id = 0;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      if (w) {
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
      } else {
        g[u].emplace_back(v, w, id);
        g[v].emplace_back(u, w, id++);
      }
    }
  }

  auto print = [&g](int bound, ll value) {
    cout << "YES\n";
    set<pair<int, int>> vis;
    for (int i = 0; i < (int)g.size(); i++) {
      for (auto &[j, w, id] : g[i]) {
        if (id >= 0) {
          if (id < bound) w = 1;
          else if (id == bound) w = value;
          else w = INT_MAX;
        }

        if (vis.emplace(minmax(i, j)).second) {
          cout << i << ' ' << j << ' ' << w << '\n';
        }
      }
    }
  };
  {
    auto d = dijkstra(g, s)[t];
    if (d < L) {
      cout << "NO\n";
      return;
    } else if (d == L) {
      print(-1, 1);
      return;
    }

    d = dijkstra(g, s, m)[t];
    if (d > L) {
      cout << "NO\n";
      return;
    }
  }

  int l = 0, r = m;
  ll res = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    auto value = dijkstra(g, s, mid)[t];
    if (value < L) {
      r = mid - 1;
      res = value;
    }
    else
      l = mid + 1;
  }
  assert(0 <= l and res > 0);

  print(l, L-res+1);
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
