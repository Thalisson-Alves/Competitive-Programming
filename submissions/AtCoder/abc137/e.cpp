#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

bool bellman_ford(const vector<vector<pair<int, ll>>> &g, int s, vector<ll> &dist, const vector<bool> &can) {
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

void dfs(const vector<vector<int>> &g, int u, vector<bool> &vis) {
  vis[u] = 1;
  for (auto x : g[u]) {
    if (not vis[x]) {
      vis[u] = 1;
      dfs(g, x, vis);
    }
  }
}

void solve()
{
  int n, m, p;
  cin >> n >> m >> p;
  vector<vector<pair<int, ll>>> g(n);
  vector<vector<int>> gr(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, p - w);
    gr[v].push_back(u);
  }

  vector<bool> vis(n);
  dfs(gr, n-1, vis);

  vector<ll> dist(n);
  if (bellman_ford(g, 0, dist, vis)) {
    cout << max(-dist[n-1], 0ll) << '\n';
  } else {
    cout << "-1\n";
  }
}

int main()
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
