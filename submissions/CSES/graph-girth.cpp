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

template <typename Undigraph> int girth(const Undigraph &g) {
  int res = INT_MAX;
  auto loop_size = [&](int u) -> void {
    vector<pair<int, int>> q({{u, -1}});
    q.reserve(g.size());
    vector<int> dist(g.size(), -1);
    dist[u] = 0;
    for (int i = 0; i < (int)q.size(); i++) {
      auto [cur, par] = q[i];
      if (2*dist[cur] >= res) return;
      for (auto x : g[cur]) if (x != par) {
        if (~dist[x]) {
          res = min(res, dist[x] + dist[cur] + 1);
        } else {
          dist[x] = dist[cur] + 1;
          q.emplace_back(x, cur);
        }
      }
    }
  };

  vector<short> vis(g.size());
  auto mark_cycle = [&](int u) -> void {
    queue<int> q({u});
    vis[u] = 1;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      for (auto v : g[cur]) {
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
        } else {
          vis[v] = 2;
        }
      }
    }
  };

  for (int i = 0; i < (int)g.size(); i++) if (!vis[i]) mark_cycle(i);
  for (int i = 0; i < (int)g.size(); i++) if (vis[i] == 2) loop_size(i);
  return res;
}

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
  auto res = girth(g);
  cout << (res == INT_MAX ? -1 : res) << '\n';
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
