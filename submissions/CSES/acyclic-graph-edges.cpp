#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

struct PhantomWeight {
  template <typename T> operator T() const { return 1; }
  template <typename T> PhantomWeight(T) {}
};
template <typename T, bool directed> struct Graph {
  using Weight = T;
  struct Edge {
    int from, to;
    T weight;
  };

  vector<vector<int>> g;
  vector<Edge> edges;

  Graph(int n) : g(n) {}
  Graph(const vector<vector<int>> &g_) : Graph((int)g_.size()) {
    for (int u = 0; u < (int)g_.size(); u++) {
      for (auto v : g_[u]) {
        if (directed or u <= v) {
          add_edge(u, v);
        }
      }
    }
  }
  Graph(const vector<vector<pair<int, Weight>>> &g_) : Graph((int)g_.size()) {
    for (int u = 0; u < (int)g_.size(); u++) {
      for (auto [v, w] : g_[u]) {
        if (directed or u <= v) {
          add_edge(u, v, w);
        }
      }
    }
  }

  int add_edge(int from, int to, T cost = 1) {
    assert(0 <= from and from < size() and 0 <= to and to < size());
    int id = (int)edges.size();
    g[from].push_back(id);
    if constexpr (not directed)
      g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }

  template <bool include_weight> struct EdgeIterator {
    const Graph &g;
    int node;
    int cur;

    EdgeIterator(const Graph &g_, int node_, int cur_ = 0) : g(g_), node(node_), cur(cur_) {}
    auto operator*() const {
      auto e = g.edges[g.g[node][cur]];
      if constexpr (include_weight)
        return pair<int, T>(e.to ^ e.from ^ node, e.weight);
      else
        return e.to ^ e.from ^ node;
    }
    bool operator!=(const EdgeIterator &rhs) const { return cur != rhs.cur; }
    void operator++() { cur++; }
    void operator++(int) { cur++; }

    EdgeIterator begin() const { return *this; }
    EdgeIterator end() const { return EdgeIterator(g, node, (int)g.g[node].size()); }
    int size() const { return static_cast<int>(g.g[node].size()); }
    bool empty() const { return !remaining(); }
    int remaining() const { return size() - cur; }

    EdgeIterator<true> with_weights() const { return EdgeIterator<true>(g, node, cur); }
  };
  EdgeIterator<false> operator[](int node) const { return EdgeIterator<false>(*this, node); }

  int size() const { return static_cast<int>(g.size()); }
  constexpr static bool is_directed() { return directed; }

  Graph reverse() const {
    Graph rev(size());
    for (const auto &e : edges)
      rev.add_edge(e.to, e.from, e.weight);
    return rev;
  }
};
template <typename T = PhantomWeight> using Digraph = Graph<T, true>;
template <typename T = PhantomWeight> using Undigraph = Graph<T, false>;

void solve()
{
  int n, m;
  cin >> n >> m;
  Undigraph<> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g.add_edge(--u, --v);
  }

  vector<int> depth(n, INT_MAX);
  vector<pair<int, int>> res;
  res.reserve(m);
  auto dfs = [&](auto &&self, int u) -> void {
    for (auto v : g[u]) if (depth[u] < depth[v]) {
      res.emplace_back(u, v);
      if (depth[v] == INT_MAX) {
        depth[v] = depth[u] + 1;
        self(self, v);
      }
    }
  };
  for (int i = 0; i < n; i++) if (depth[i] == INT_MAX) {
    depth[i] = 0;
    dfs(dfs, i);
  }
  for (auto [u, v] : res)
    cout << u + 1 << ' ' << v + 1 << '\n';
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
