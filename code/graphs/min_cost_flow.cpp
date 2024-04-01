/* Min Cost Flow
 *
 * Calculates the minimum cost flow in a graph.
 *
 * Methods:
 * - MinCostFlow(n): initializes the data structures for a graph with n vertices.
 *   - O(n)
 * - add_edge(u, v, cap, cost): adds an edge between vertices u and v with capacity `cap` and cost `cost`.
 *   - O(1)
 * - flow(s, t, flow_limit): calculates the minimum cost flow from vertex `s` to vertex `t` with flow limit `flow_limit`.
 *   - O(V * E * f), where f is the flow limit
 * - paths(s, t): returns the nodes used on paths of the minimum cost flow from vertex `s` to vertex `t`.
 *   - O((V + E) * f), where f is the flow limit used in the flow method
 *
 * Tested on:
 * - https://cses.fi/problemset/task/2130/
 * - https://codeforces.com/gym/103640/problem/h
 */
template <typename T> struct MinCostFlow {
  struct Edge {
    int to;
    T cap, cost;
    T cap_used;
  };
  int n;
  vector<Edge> e;
  vector<vector<int>> g;
  vector<T> dis;
  vector<int> pre;

  MinCostFlow() {}
  MinCostFlow(int n_) : n(n_), g(n) {}

  void add_edge(int u, int v, T cap, T cost) {
    assert(u < (int)g.size());
    assert(v < (int)g.size());
    g[u].push_back((int)e.size());
    e.emplace_back(v, cap, cost, 0);
    g[v].push_back((int)e.size());
    e.emplace_back(u, 0, -cost, 0);
  }

  // {flow, cost}
  pair<T, T> flow(int s, int t, T flow_limit = numeric_limits<T>::max()) {
    T flow = 0, cost = 0;
    while (flow < flow_limit and shortest_paths(s, t)) {
      T aug = numeric_limits<int>::max();
      for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
        aug = min({flow_limit - flow, aug, e[pre[i]].cap});
      }
      for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
        e[pre[i]].cap -= aug;
        e[pre[i] ^ 1].cap += aug;

        e[pre[i]].cap_used += aug;
        e[pre[i] ^ 1].cap_used -= aug;
      }
      flow += aug;
      cost += aug * dis[t];
    }
    return {flow, cost};
  }

  // Needs to be called after flow method
  vector<vector<int>> paths(int s, int t) {
    vector<vector<int>> p;
    while (true) {
      int cur = s;
      auto &res = p.emplace_back();
      res.push_back(cur);
      while (cur != t) {
        bool found = false;
        for (auto i : g[cur]) {
          auto &[v, _, cost, cap] = e[i];
          if (cap > 0) {
            --cap;
            res.push_back(cur = v);
            found = true;
            break;
          }
        }

        if (!found)
          break;
      }

      if (cur != t) {
        p.pop_back();
        break;
      }
    }

    return p;
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
        auto [v, cap, cost, _] = e[i];
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
