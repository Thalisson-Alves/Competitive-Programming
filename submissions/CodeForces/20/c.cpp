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
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1},  {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

vector<int> dijkstra(const vector<vector<pair<int, ll>>> &g, int s)
{
  vector<ll> min_cost(g.size(), LLONG_MAX);
  min_cost[s] = 0;

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.emplace(0, s);

  vector<int> came_from(g.size(), -1);

  while (not pq.empty())
  {
    auto [cost, cur] = pq.top(); pq.pop();
    if (cost != min_cost[cur]) continue;

    for (auto [x, y] : g[cur])
    {
      auto new_cost = min_cost[cur] + y;
      if (new_cost < min_cost[x])
      {
        min_cost[x] = new_cost;
        pq.emplace(new_cost, x);

        came_from[x] = cur;
      }
    }
  }

  return came_from;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  auto came_from = dijkstra(g, 0);
  vector<int> ans;

  int cur = n-1;
  while (cur != -1) {
    ans.push_back(cur+1);
    if (cur == 0) break;

    cur = came_from[cur];
  }

  if (cur == 0) {
    reverse(all(ans));
    for (auto x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
  } else {
    cout << "-1\n";
  }
}

int32_t main() {
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
