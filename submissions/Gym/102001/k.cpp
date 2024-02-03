#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

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

  int add_edge(int from, int to, T cost = 1) {
    assert(0 <= from and from < size() and 0 <= to and to < size());
    int id = (int)edges.size();
    g[from].push_back(id);
    if constexpr (not directed)
      g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }

  struct EdgeIterator {
    const Graph &g;
    int node;
    int cur;

    EdgeIterator(const Graph &g_, int node_, int cur_ = 0) : g(g_), node(node_), cur(cur_) {}
    pair<int, Weight> operator*() const {
      auto e = g.edges[g.g[node][cur]];
      return {e.to ^ e.from ^ node, e.weight};
    }
    bool operator!=(const EdgeIterator &rhs) const { return cur != rhs.cur; }
    void operator++() { cur++; }
    void operator++(int) { cur++; }

    EdgeIterator begin() const { return *this; }
    EdgeIterator end() const { return EdgeIterator(g, node, (int)g.g[node].size()); }
    int size() const { return g.g[node].size(); }
    int remaining() const { return size() - cur; }
  };
  EdgeIterator next(int node) const { return EdgeIterator(*this, node); }
  EdgeIterator operator[](int node) const { return EdgeIterator(*this, node); }

  int size() const { return static_cast<int>(g.size()); }
  constexpr bool is_directed() const { return directed; }

  Graph reverse() const {
    Graph rev(size());
    for (const auto &e : edges)
      rev.add_edge(e.to, e.from, e.weight);
    return rev;
  }
};
template <typename T = PhantomWeight> using Digraph = Graph<T, true>;
template <typename T = PhantomWeight> using Undigraph = Graph<T, false>;

enum class EdgeType {
  TREE = 1,
  FORWARD,
  CROSS,
  BACK,
};
template <typename Graph> void dfs_tree(const Graph &g, auto f) {
  static_assert(std::is_invocable_r_v<void, decltype(f), int, int, EdgeType>);

  vector<bool> vis(g.edges.size());
  vector<int> tin(g.size()), tout(g.size());
  int timer = 1;
  auto dfs = [&](auto &&self, int u, int p) -> void {
    tin[u] = timer++;
    for (auto id : g.g[u]) if (!vis[id]) {
      vis[id] = 1;

      auto [from, to, _] = g.edges[id];
      int v = from ^ to ^ u;

      if (v == p) continue;

      if (!tin[v]) {
        self(self, v, u);
        f(u, v, EdgeType::TREE);
      } else if (tin[v] < tin[u]) {
        f(u, v, (tout[v] ? EdgeType::CROSS : EdgeType::BACK));
      } else {
        f(u, v, EdgeType::FORWARD);
      }
    }
    tout[u] = timer++;
  };

  for (int u = 0; u < g.size(); u++) {
    if (!tin[u]) dfs(dfs, u, -1);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;

  Undigraph<> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g.add_edge(--u, --v);
  }

  vector<vector<int>> con(n), tree(n);
  dfs_tree(g, [&](int u, int v, EdgeType t) {
    switch (t) {
    case EdgeType::TREE: {
      if (con[v].size() & 1) {
        con[v].push_back(u);
      } else {
        con[u].push_back(v);
      }
    } break;
    case EdgeType::BACK: {
      con[v].push_back(u);
    } break;
    default:
      break;
    }
  });

  vector<tuple<int, int, int>> res;
  for (int i = 0; i < n; i++) {
    const auto &c = con[i];
    for (int j = 1; j < (int)c.size(); j+=2) {
      res.emplace_back(c[j-1]+1, i+1, c[j]+1);
    }
  }

  cout << res.size() << '\n';
  for (auto [a, b, c] : res) cout << a << ' ' << b << ' ' << c << '\n';
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
