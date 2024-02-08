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

// O(n + m)
template <typename T> struct BlockCutTree {
  vector<vector<int>> blocks, tree;
  vector<vector<pair<int, int>>> block_edges;
  vector<int> articulation, pos;

  BlockCutTree(const Undigraph<T> &g) : articulation(g.size()), pos(g.size(), -1) {
    int t = 0;
    vector<int> id(g.size(), -1);
    stack<int> s1;
    stack<pair<int, int>> s2;
    for (int i = 0; i < (int)g.size(); i++)
      if (id[i] == -1)
        dfs(g, i, -1, t, id, s1, s2);

    tree.resize(blocks.size());
    for (int i = 0; i < (int)g.size(); i++)
      if (articulation[i])
        pos[i] = (int)tree.size(), tree.emplace_back();

    for (int i = 0; i < (int)blocks.size(); i++) {
      for (auto j : blocks[i]) {
        if (not articulation[j]) pos[j] = i;
        else tree[i].push_back(pos[j]), tree[pos[j]].push_back(i);
      }
    }
  }

private:
  int dfs(const Undigraph<T> &g, int i, int p, int &t, vector<int> &id, stack<int> &s1, stack<pair<int, int>> &s2) {
    int lo = id[i] = t++;
    s1.push(i);

    if (p != -1) s2.emplace(i, p);
    for (auto [j, _] : g[i])
      if (j != p and id[j] != -1)
        s2.emplace(i, j);

    for (auto [j, _] : g[i]) if (j != p) {
      if (id[j] == -1) {
        int val = dfs(g, j, i, t, id, s1, s2);
        lo = min(lo, val);

        if (val >= id[i]) {
          articulation[i]++;
          blocks.emplace_back(1, i);
          for (; blocks.back().back() != j; s1.pop())
            blocks.back().push_back(s1.top());

          block_edges.emplace_back(1, s2.top());
          s2.pop();
          for (; block_edges.back().back() != make_pair(j, i); s2.pop())
            block_edges.back().push_back(s2.top());
        }
      } else {
        lo = min(lo, id[j]);
      }
    }

    if (p == -1 and articulation[i]) --articulation[i];
    return lo;
  }
};

void solve()
{
  for (int m, t = 1; cin >> m, m; t++) {
    vector<pair<int, int>> es(m);
    int mx = 0;
    for (auto &[u, v] : es) cin >> u >> v, --u, --v, mx = max({mx, u, v});
    Undigraph<> g(mx+1);
    for (auto [u, v] : es) g.add_edge(u, v);
    BlockCutTree cut(g);

    ll a = 0, b = 1;
    for (int i = 0; i < (int)cut.blocks.size(); i++) if (cut.tree[i].size() <= 1) {
      a++;
      b *= (ll)(cut.blocks[i].size() - cut.tree[i].size());
    }

    if (cut.blocks.size() == 1) {
      a = 2;
      b = (ll)(cut.blocks[0].size() * (cut.blocks[0].size() - 1) / 2ll);
    }

    cout << "Case " << t << ": " << a << ' ' << b << '\n';
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
