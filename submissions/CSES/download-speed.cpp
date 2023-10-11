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

template <typename T>
struct MaxFlow {
  vector<vector<int>> adj;
  vector<vector<T>> capacity;

  MaxFlow(int n) : adj(n), capacity(n, vector<T>(n)) {}
  MaxFlow(const vector<vector<int>> &g, const vector<vector<T>> &cap) : adj(g), capacity(cap) {}

  void add(int u, int v, T w) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v] += w;
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
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    mf.add(u-1, v-1, w);
  }
  cout << mf.maxflow(0, n-1) << '\n';
}

int main()
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

