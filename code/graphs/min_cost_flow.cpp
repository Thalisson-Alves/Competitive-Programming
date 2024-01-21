template <typename T> struct MinCostFLow {
  struct Edge {
    int to;
    T cap, cost;
  };
  int n;
  vector<Edge> e;
  vector<vector<int>> g;
  vector<T> dis;
  vector<int> pre;

  MinCostFLow() {}
  MinCostFLow(int n_) : n(n_), g(n) {}

  void add_edge(int u, int v, T cap, T cost) {
    g[u].push_back((int)e.size());
    e.emplace_back(v, cap, cost);
    g[v].push_back((int)e.size());
    e.emplace_back(u, 0, -cost);
  }

  // {flow, cost}
  pair<T, T> flow(int s, int t) {
    T flow = 0, cost = 0;
    while (shortest_paths(s, t)) {
      T aug = numeric_limits<int>::max();
      for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
        aug = min(aug, e[pre[i]].cap);
      }
      for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
        e[pre[i]].cap -= aug;
        e[pre[i] ^ 1].cap += aug;
      }
      flow += aug;
      cost += aug * dis[t];
    }
    return {flow, cost};
  }

private:
  bool shortest_paths(int s, int t) {
    dis.assign(n, numeric_limits<T>::max());
    pre.assign(n, -1);

    vector<bool> inq(n, false);
    queue<int> q;

    dis[s] = 0;
    q.push(s);

    while (not q.empty()) {
      auto u = q.front();
      q.pop();
      inq[u] = false;

      for (auto i : g[u]) {
        auto [v, cap, cost] = e[i];
        auto new_dist = dis[u] + cost;
        if (cap > 0 and dis[v] > new_dist) {
          dis[v] = new_dist;
          pre[v] = i;
          if (not inq[v]) {
            inq[v] = true;
            q.push(v);
          }
        }
      }
    }

    return dis[t] != numeric_limits<T>::max();
  }
};
