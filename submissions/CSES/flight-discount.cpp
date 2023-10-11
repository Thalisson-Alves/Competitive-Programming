#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
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
  int n, m;
  cin >> n >> m;
 
  vector<vector<pair<int, ll>>> g(n), gr(n);
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    g[--a].emplace_back(--b, c);
    gr[b].emplace_back(a, c);
  }
 
  auto start = dijkstra(g, 0);
  auto end = dijkstra(gr, n-1);
 
  ll ans = LLONG_MAX;
  for (int i = 0; i < n; i++)
  {
    for (auto [x, y] : g[i])
    {
      if (start[i] == LLONG_MAX or end[x] == LLONG_MAX)
        continue;
 
      ans = min(ans, start[i] + y / 2 + end[x]);
    }
  }
 
  cout << ans << '\n';
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  solve();
 
  return 0;
}
