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

vector<ll> dijkstra(const vector<vector<pair<int, ll>>> &g, int s)
{
  vector<ll> min_cost(g.size(), LLONG_MAX);
  min_cost[s] = 0;

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.emplace(0, s);

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
      }
    }
  }

  return min_cost;
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<pair<int, ll>>> g(n);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      string s;
      cin >> s;
      if (s[0] == 'x') continue;
      auto value = stoll(s);
      g[i].emplace_back(j, value);
      g[j].emplace_back(i, value);
    }
  }

  auto dist = dijkstra(g, 0);
  cout << *max_element(all(dist)) << '\n';
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
