#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

template <typename T>
struct MinCostFLow {
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
 
    using PQ = pair<T, int>;
    priority_queue<PQ, vector<PQ>, greater<PQ>> pq;
 
    dis[s] = 0;
    pq.emplace(0, s);
 
    while (not pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
 
      if (dis[u] != d) continue;
      for (auto i : g[u]) {
        auto [v, cap, cost] = e[i];
        auto new_dist = d + cost;
        if (cap > 0 and dis[v] > new_dist) {
          dis[v] = new_dist;
          pre[v] = i;
          pq.emplace(dis[v], v);
        }
      }
    }

    return dis[t] != numeric_limits<T>::max();
  }
};

void solve()
{
  int n;
  cin >> n;

  vector<vector<int>> g(n+2, vector<int>(n+2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> g[i][j];
    }
  }

  if (n&1) ++n;
  MinCostFLow<ll> mcf(n + 3);
  const int s = 0, t = n+2;
  for (int i = 1; i <= n; i += 2) {
    mcf.add_edge(s, i, 1, 0);
    for (int j = 2; j <= n; j += 2) {
      mcf.add_edge(i, j, 1, g[i][j] + g[i][j-2]);
    }
  }
  for (int i = 2; i <= n; i += 2) {
    mcf.add_edge(i, t, 1, 0);
  }

  cout << mcf.flow(s, t).second << '\n';
}

int32_t main()
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
