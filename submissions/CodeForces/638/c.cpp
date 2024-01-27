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

/*
Used to define recursive lambdas,  first argument is the function itself

auto value = y_combinator([](auto &&gcd, int a, int b) -> int {
  return b ? gcd(b, a % b) : a;
});
*/
template <class Fun> class y_combinator_result {
  Fun fun_;

  public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

void solve() {
  int n;
  cin >> n;

  Undigraph<> g(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    g.add_edge(--u, --v);
  }

  vector<int> color(n-1, -1);
  y_combinator([&](auto &&dfs, int u, int cant=-1) -> void {
    int cur = 0;
    for (auto id : g.g[u]) if (color[id] == -1) {
      if (cur == cant) ++cur;
      color[id] = cur;
      const auto &e = g.edges[id];
      auto v = e.to ^ e.from ^ u;
      dfs(v, color[id]);
      ++cur;
    }
  })(0);

  vector<vector<int>> res(*max_element(all(color)) + 1);
  for (int i = 0; i < n-1; i++) {
    res[color[i]].push_back(i);
  }

  cout << res.size() << '\n';
  for (auto &x : res) {
    cout << x.size();
    for (auto y : x)
      cout << ' ' << y+1;
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
