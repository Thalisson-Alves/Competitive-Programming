/* Dominator Tree
 *
 * Dominator Tree is a tree that represents the dominator relationship of a
 * directed graph. The dominator relationship is defined as follows:
 * - A node u dominates a node v if every path from the root to v must pass
 *   through u.
 * - The root node dominates all other nodes and has no dominators.
 * - A node u is said to be the immediate dominator of a node v if u is the
 *   closest dominator of v.
 * - The immediate dominator of a node is unique.
 *
 * Fields:
 * - g: the directed graph.
 * - gr: the reversed graph.
 * - tree: the dominator tree.
 * - bucket: stores a list of nodes for which i is the semi-dominator.
 * - tin: the preorder traversal time of each node in the original graph.
 * - rev: the node corresponding to the preorder traversal time.
 * - par: the parent of each node in the original graph.
 * - sdom: the semidominator of each node.
 * - dom: the dominator of each node.
 *
 * Methods:
 * - add_edge(u, v): adds a directed edge from u to v.
 *   - O(1)
 * - build(root): builds the dominator tree.
 *   - O((V + E) log V)
 */
struct DominatorTree {
  vector<vector<int>> g, gr, tree, bucket;
  vector<int> tin, rev, par, sdom, dom;

private:
  vector<int> label, dsu;

public:
  DominatorTree(int n)
      : g(n), gr(n), tree(n), bucket(n), tin(n, -1), rev(n, -1), par(n, -1),
        sdom(n), dom(n), label(n), dsu(n) {}
  DominatorTree(const vector<vector<int>> &g_, int root = 0)
      : DominatorTree((int)g_.size()) {
    g = g_;
    build(root);
  }

  void add_edge(int u, int v) { g[u].push_back(v); }

  void build(int root = 0) {
    int t = 0;
    auto dfs = [&](auto &&self, int u) -> void {
      tin[u] = t; rev[t] = u;
      label[t] = t; sdom[t] = t;
      dsu[t] = t;
      ++t;
      for (auto v : g[u]) {
        if (tin[v] < 0) {
          self(self, v);
          par[tin[v]] = tin[u];
        }
        gr[tin[v]].push_back(tin[u]);
      }
    };
    dfs(dfs, root);

    for (int i = t - 1; ~i; --i) {
      for (auto x : gr[i])
        sdom[i] = min(sdom[i], sdom[dsu_find(x)]);
      if (i) bucket[sdom[i]].push_back(i);
      for (auto x : bucket[i]) {
        int v = dsu_find(x);
        if (sdom[v] == sdom[x]) dom[x] = sdom[x];
        else dom[x] = v;
      }
      if (i) dsu_join(par[i], i);
    }

    for (int i = 1; i < t; i++) {
      if (dom[i] != sdom[i]) dom[i] = dom[dom[i]];
      tree[rev[i]].push_back(rev[dom[i]]);
      tree[rev[dom[i]]].push_back(rev[i]);
    }
  }

private:
  int dsu_find(int u, int x = 0) {
    if (u == dsu[u]) return x ? -1 : u;
    int v = dsu_find(dsu[u], x + 1);
    if (v < 0) return u;
    if (sdom[label[dsu[u]]] < sdom[label[u]])
      label[u] = label[dsu[u]];
    dsu[u] = v;
    return x ? v : label[u];
  }

  void dsu_join(int u, int v) { dsu[v] = u; }
};
