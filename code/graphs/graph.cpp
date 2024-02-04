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
    int size() const { return static_cast<int>(g.g[node].size()); }
    int remaining() const { return size() - cur; }
  };
  EdgeIterator next(int node) const { return EdgeIterator(*this, node); }
  EdgeIterator operator[](int node) const { return EdgeIterator(*this, node); }

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
