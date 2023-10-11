#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
void dijkstra(const vector<vector<pair<int, ll>>> &g, int s, vector<priority_queue<ll>> &best, int k)
{
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.emplace(0, s);
 
  while (not pq.empty())
  {
    auto [cost, cur] = pq.top(); pq.pop();
    if (not best[cur].empty() and cost > best[cur].top()) continue;
 
    for (auto [x, y] : g[cur])
    {
      if ((int)best[x].size() < k or cost + y < best[x].top())
      {
        best[x].push(cost + y);
        pq.emplace(cost + y, x);
      }
 
      if ((int)best[x].size() > k)
        best[x].pop();
    }
  }
}
 
void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
 
  vector<vector<pair<int, ll>>> g(n);
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    g[--a].emplace_back(--b, c);
  }
 
  vector<priority_queue<ll>> best(n);
  dijkstra(g, 0, best, k);
 
  vector<ll> ans(k);
  for (int i = 0; i < k; i++)
  {
    ans[k-i-1] = best[n-1].top();
    best[n-1].pop();
  }
 
  for (int i = 0; i < k; i++)
    cout << ans[i] << " \n"[i == k-1];
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  solve();
 
  return 0;
}
