#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

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

  struct NodeIterator {
    const Graph &g; int cur;

    NodeIterator(const Graph &g_, int cur_ = 0) : g(g_), cur(cur_) {}
    int operator*() const { return cur; }
    bool operator!=(const NodeIterator &rhs) const { return cur != rhs.cur; }
    void operator++() { cur++; }
    void operator++(int) { cur++; }

    NodeIterator begin() const { return *this; }
    NodeIterator end() const { return NodeIterator(g, g.size()); }
  };
  NodeIterator nodes() const { return NodeIterator(*this); }
  NodeIterator begin() const { return nodes(); }
  NodeIterator end() const { return nodes().end(); }

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
template <typename T = int> using Digraph = Graph<T, true>;
template <typename T = int> using Undigraph = Graph<T, false>;

template <typename T> vector<int> bridge_components(const Undigraph<T> &g) {
  vector<int> tin(g.size()), tout(g.size()), low(g.size()), res(g.size());
  stack<int> st;
  int timer = 0, comp_id = 0;

  auto dfs = [&](auto &&self, int u, int p) -> void {
    tin[u] = low[u] = timer++;
    st.push(u);

    for (auto [v, _] : g[u]) if (v != p) {
      if (tin[v]) {
        low[u] = min(low[u], tin[v]);
      } else {
        self(self, v, u);
        low[u] = min(low[u], low[v]);
      }
    }

    if (tin[u] == low[u]) {
      ++comp_id;
      int v;
      do {
        v = st.top();
        st.pop();
        res[v] = comp_id;
      } while (v != u);
    }
  };

  for (int i = 0; i < g.size(); i++) {
    if (!tin[i])
      dfs(dfs, i, -1);
  }

  return res;
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

  auto comp = bridge_components(g);
  vector<int> hist(*max_element(all(comp))+1);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    if (++hist[comp[i]] > hist[comp[mx]])
      mx = i;
  }

  cout << hist[comp[mx]] << '\n';

  vector<short> vis(n);
  vector<pair<int, int>> res(m);
  auto dfs = [&](auto &&self, int u, int p) -> void {
    vis[u] = 1;
    for (int id : g.g[u]) {
      auto e = g.edges[id];
      int v = e.to ^ e.from ^ u;
      if (v == p) continue;
      if (vis[v] != 2)
        res[id] = {u, v};
      if (!vis[v])
        self(self, v, u);
    }
    vis[u] = 2;
  };
  dfs(dfs, mx, -1);

  for (auto [v, u] : res)
    cout << u+1 << ' ' << v+1 << '\n';
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
