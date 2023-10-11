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

bool bellman_ford(const vector<vector<pair<int, ll>>> &g, int s, vector<ll> &dist, const vector<char> &can)
{
  int n = (int)g.size();
  dist.assign(n, LLONG_MAX);

  vector<int> count(n);
  vector<char> in_queue(n);
  queue<int> q;

  dist[s] = 0;
  q.push(s);
  in_queue[s] = true;

  while (not q.empty())
  {
    int cur = q.front();
    q.pop();
    in_queue[cur] = false;

    for (auto [to, w] : g[cur])
    {
      if (not can[to]) continue;
      if (dist[cur] + w < dist[to])
      {
        dist[to] = dist[cur] + w;
        if (not in_queue[to])
        {
          q.push(to);
          in_queue[to] = true;
          count[to]++;
          if (count[to] > n)
            return false;
        }
      }
    }
  }

  return true;
}

void dfs(const vector<vector<int>> &g, int s, vector<char> &vis)
{
  vis[s] = true;
  for (auto to : g[s])
    if (not vis[to])
      dfs(g, to, vis);
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> g(n);
  vector<vector<int>> gr(n);
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].emplace_back(b, -c);
    gr[b].push_back(a);
  }

  vector<char> can(n);
  dfs(gr, n-1, can);
  dbg(vector<int>(all(can)));

  vector<ll> dist;
  auto has_cycle = not bellman_ford(g, 0, dist, can);
  dbg(dist, has_cycle);
  if (has_cycle)
    cout << "-1\n";
  else
    cout << -dist[n-1] << '\n';
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
 
