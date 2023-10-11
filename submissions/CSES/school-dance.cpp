#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

template <typename T, bool Undirected=false>
struct MaxFlow {
  vector<set<int>> adj;
  vector<vector<T>> capacity;
 
  MaxFlow(int n) : adj(n), capacity(n, vector<T>(n)) {}
  MaxFlow(const vector<set<int>> &g, const vector<vector<T>> &cap) : adj(g), capacity(cap) {}
 
  void add(int u, int v, T w) {
    adj[u].insert(v);
    adj[v].insert(u);
    capacity[u][v] += w;
    if constexpr (Undirected)
      capacity[v][u] += w;
  }
 
  T maxflow(int s, int t) {
    T flow = T();
    vector<int> parent(adj.size());
    for (T new_flow; (new_flow = bfs(s, t, parent)); ) {
      flow += new_flow;
      for (int cur = t; cur != s; cur = parent[cur]) {
        int prev = parent[cur];
        capacity[prev][cur] -= new_flow;
        capacity[cur][prev] += new_flow;
      }
    }
    return flow;
  }
 
  vector<int> mincut(int s, int t) {
    maxflow(s, t);
    vector<int> cut(adj.size(), 1);
    dfs(s, cut);
    return cut;
  }
 
  void dfs(int s, vector<int> &cut) const {
    cut[s] = 0;
    for (auto next : adj[s]) if (cut[next] and capacity[s][next])
      dfs(next, cut);
  }
 
  T bfs(int s, int t, vector<int> &parent) const {
    fill(all(parent), -1);
    parent[s] = -2;
    queue<pair<int, T>> q;
    q.emplace(s, numeric_limits<T>::max());
 
    while (not q.empty()) {
      auto [cur, flow] = q.front();
      q.pop();
 
      for (int next : adj[cur]) if (parent[next] == -1 and capacity[cur][next]) {
        parent[next] = cur;
        auto new_flow = min(flow, capacity[cur][next]);
        if (next == t)
          return new_flow;
        q.emplace(next, new_flow);
      }
    }
 
    return T();
  }
};

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  MaxFlow<ll> mf(n+m+2);
  vector<vector<char>> edges(n, vector<char>(m));
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    v += n;
    mf.add(u, v, 1);
    edges[u][v-n] = 1;
  }
  for (int i = 0; i < n; i++)
    mf.add(n+m, i, 1);
  for (int i = 0; i < m; i++)
    mf.add(i+n, n+m+1, 1);
 
  cout << mf.maxflow(n+m, n+m+1) << '\n';
  set<pair<int, int>> ans;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (mf.capacity[j+n][i])
        ans.emplace(i, j);
    }
  }
  for (auto [a, b] : ans)
    cout << a+1 << ' ' << b+1 << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}
