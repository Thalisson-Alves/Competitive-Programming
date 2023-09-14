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
