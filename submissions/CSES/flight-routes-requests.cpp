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

/* Strongly Connected Components
 *
 * Finds the strongly connected components of a directed graph, and builds the SCC tree.
 *
 * Fields:
 * - size: number of strongly connected components.
 * - comp_id: for each vertex, the id of the strongly connected component it belongs to.
 * - comps: for each strongly connected component, the list of vertices it contains.
 * - g: the SCC tree.
 *
 * Methods:
 * - SCC(g): builds the SCCs and the SCC tree.
 *   - O(n + m)
 * - minimum_augmentation: returns a list of edges to add to the graph to make it strongly connected.
 *   - O(n + m)
 *
 * Tested on:
 * - https://cses.fi/problemset/task/1685/
 */
template <typename Digraph> struct SCC {
  int size;
  vector<int> comp_id;
  vector<vector<int>> comps;
  Digraph g;

  SCC(const Digraph &g_) : size(0), comp_id(g_.size(), -1), g(0) {
    int timer = 1;
    vector<int> tin(g_.size()), st;
    st.reserve(g_.size());
    auto dfs = [&](auto&& self, int u) -> int {
      int low = tin[u] = timer++, now = (int)st.size();
      st.push_back(u);
      for (auto v : g_[u])
      if (comp_id[v] < 0)
        low = min(low, tin[v] ? tin[v] : self(self, v));
      if (tin[u] == low) {
        for (int i = now; i < (int)st.size(); i++)
          comp_id[st[i]] = size;
        st.resize(now);
        size++;
      }
      return low;
    };
    for (int i = 0; i < g_.size(); i++)
      if (!tin[i]) dfs(dfs, i);
    comps.resize(size);
    for (int i = 0; i < (int)comp_id.size(); i++) comps[comp_id[i]].push_back(i);

    g = [&]() {  // build scc tree
      set<pair<int, int>> edges;
      for (auto [u, v, _] : g_.edges) {
        if (comp_id[u] != comp_id[v])
          edges.emplace(comp_id[u], comp_id[v]);
      }
      auto tree = Digraph(size);
      for (auto [u, v] : edges)
        tree.add_edge(u, v);
      return tree;
    }();
  }

  vector<pair<int, int>> minimum_augmentation() const {
    if (g.size() <= 1) return {};

    vector<bool> zero_out(g.size(), 1), zero_in(g.size(), 1);
    for (int i = 0; i < (int)g.size(); i++) {
      zero_out[i] = g[i].empty();
      for (auto x : g[i])
      zero_in[x] = false;
    }

    vector<bool> vis(g.size());
    auto dfs = [&](auto &&self, int u) {
      vis[u] = 1;
      if (zero_out[u]) return u;
      for (auto v : g[u]) if (!vis[v]) {
        auto x = self(self, v);
        if (~x) return x;
      }
      return -1;
    };

    vector<int> sources, sinks;
    vector<int> unmatched_sources, unmatched_sinks;

    for (int i = 0; i < (int)g.size(); i++) if (zero_in[i]) {
      auto sink = dfs(dfs, i);
      if (~sink) {
        sources.push_back(i);
        sinks.push_back(sink);
      } else {
        unmatched_sources.push_back(i);
      }
    }

    for (int i = 0; i < (int)g.size(); i++) {
      if (zero_out[i] and !vis[i])
        unmatched_sinks.push_back(i);
    }

    int matches = (int)sources.size();
    sources.insert(sources.end(), all(unmatched_sources));
    sinks.insert(sinks.end(), all(unmatched_sinks));
    int mn = (int)sources.size(), mx = (int)sinks.size();
    if (mn > mx) swap(mn, mx);

    vector<pair<int, int>> res;
    res.reserve(mx);

    res.emplace_back(0, matches - 1);
    for (int i = 1; i < matches; i++) res.emplace_back(i, i-1);
    for (int i = matches; i < mn; i++) res.emplace_back(i, i);
    for (int i = mn; i < (int)sources.size(); i++) res.emplace_back(0, i);
    for (int i = mn; i < (int)sinks.size(); i++) res.emplace_back(i, 0);
    for (auto &[a, b] : res) a = comps[sinks[a]][0], b = comps[sources[b]][0];
    return res;
  }
};

struct UFDS {
  vector<int> ps, sz;
  int components;

  UFDS(int n) : ps(n), sz(n, 1), components(n) {
    iota(all(ps), 0);
  }

  int find(int x) {
    return (x == ps[x] ? x : (ps[x] = find(ps[x])));
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    ps[y] = x;
    sz[x] += sz[y];
    --components;
    return true;
  }
};

void solve()
{
  int n, m;
  cin >> n >> m;
  Digraph<> g(n);
  UFDS ufds(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g.add_edge(--u, --v);
    ufds.join(u, v);
  }

  SCC scc(g);
  vector<bool> cy(n);
  for (int i = 0; i < n; i++) if (!cy[ufds.find(i)]) {
    cy[ufds.find(i)] = (scc.comps[scc.comp_id[i]].size() > 1);
  }

  int res = 0;
  for (int i = 0; i < n; i++) if (ufds.find(i) == i) {
    res += ufds.sz[i] - !cy[i];
  }

  cout << res << '\n';
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
