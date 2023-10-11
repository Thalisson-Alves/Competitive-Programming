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
  int n, m;
  cin >> n >> m;
  MaxFlow<ll> mf(n);
  vector<vector<int>> edges(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    mf.add(u, v, 1);
    edges[u].push_back(v);
  }
 
  cout << mf.maxflow(0, n-1) << '\n';
  dbg(mf.capacity);
  while (true) {
    int cur = 0;
    vector<int> ans{cur};
    while (cur != n-1)
    {
      int nxt = -1;
      for (auto i : edges[cur])
      {
        if (mf.capacity[i][cur])
        {
          nxt = i;
          break;
        }
      }
 
      if (nxt == -1) break;
      mf.capacity[nxt][cur] = 0;
      ans.push_back(cur = nxt);
      dbg(cur);
    }
 
    if (cur < n-1) break;
    cout << ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); i++)
      cout << ans[i] + 1 << " \n"[i == (int)ans.size()-1];
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
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}
