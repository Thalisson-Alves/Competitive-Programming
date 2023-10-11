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

pair<int, vector<int>> bellman_ford(const vector<vector<pair<int, ll>>> &g, int s, vector<ll> &dist)
{
  int n = (int)g.size();

  vector<int> count(n);
  vector<char> in_queue(n);
  queue<int> q;

  dist[s] = 0;
  q.push(s);
  in_queue[s] = true;

  vector<int> cycle(n, -1);
  bool found_cycle = false;
  while (not q.empty())
  {
    int cur = q.front();
    q.pop();
    in_queue[cur] = false;

    for (auto [to, w] : g[cur])
    {
      if (dist[cur] + w < dist[to])
      {
        dist[to] = dist[cur] + w;
        if (not in_queue[to])
        {
          q.push(to);
          in_queue[to] = true;
          ++count[to];
          if (not found_cycle and count[to] > n)
            found_cycle = true;

          if (found_cycle)
          {
            dbg(cur, to);
            if (cycle[to] == cur and count[to] > n + 3)
              return {cur, cycle};
            cycle[to] = cur;
          }
        }
      }
    }
  }

  return {-1, {}};
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> g(n);
  for (int i = 0; i < m; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].emplace_back(b, c);
  }

  vector<ll> dist(n, LLONG_MAX);
  int cur = -1;
  vector<int> cycle;
  for (int i = 0; i < n; i++)
  {
    if (dist[i] != LLONG_MAX) continue;
    auto x = bellman_ford(g, i, dist);
    if (x.first == -1) continue;
    cur = x.first;
    cycle = x.second;
    dbg(cycle);
    break;
  }
  dbg(cycle);
  if (cur == -1)
  {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector<int> path;
  vector<char> vis(n);
  path.push_back(cur);
  while (not vis[cur])
  {
    vis[cur] = true;
    cur = cycle[cur];
    path.push_back(cur);
    assert(cur != -1);
  }
  reverse(all(path));
  for (int i = 0; i < (int)path.size(); i++)
  {
    cout << path[i] + 1 << " \n"[i == (int)path.size() - 1];
  }
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
 
