#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

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
        aug = min(aug, e[pre[i]].cap);
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
            cap = 0;
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

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  MinCostFlow<int> mcf(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    mcf.add_edge(--u, --v, 1, 1);
  }

  auto [flow, cost] = mcf.flow(0, n - 1, k);
  if (flow < k) {
    cout << "-1\n";
    return;
  }

  cout << cost << '\n';
  auto res = mcf.paths(0, n - 1);
  assert((int)res.size() >= k);
  for (int i = 0; i < k; i++) {
    cout << res[i].size() << '\n';
    for (auto x : res[i])
      cout << x + 1 << ' ';
    cout << '\n';
  }
}

int32_t main() {
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
