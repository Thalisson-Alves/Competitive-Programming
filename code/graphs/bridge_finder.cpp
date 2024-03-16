/* Bridge Finder
 *
 * Given an undirected graph, finds all bridges and connected components ONLINE.
 *
 * Fields:
 * - bridges_cnt: the number of bridges in the graph.
 * - comp_cnt: the number of connected components in the graph.
 *
 * Methods:
 * - BridgeFinder(n): initializes the data structures for a graph with n vertices.
 *   - O(n)
 * - add_edge(a, b): adds an edge between vertices a and b to the graph.
 *   - O(log(n))
 * - is_bridge(u, v): returns whether the edge (u, v) would be a bridge if it's in the graph
 *   - O(1) amortized
 * - find_2ecc(v): returns the 2-edge connected component of vertex v.
 *   - O(1) amortized
 * - find_cc(v): returns the 1-edge connected component of vertex v.
 *   - O(1) amortized
 *
 * Tested on:
 * - https://cses.fi/problemset/task/1677
 * - https://cses.fi/problemset/task/2076
 */
struct BridgeFinder {
  int bridges_cnt, comp_cnt;
private:
  vector<int> dsu_2ecc, dsu_cc, dsu_cc_size;
  vector<int> parent, last_visit;
  int lca_iteration;

public:
  BridgeFinder(int n) : bridges_cnt(0), comp_cnt(n), dsu_2ecc(n), dsu_cc(n), dsu_cc_size(n, 1), parent(n, -1), last_visit(n), lca_iteration(0) {
    for (int i = 0; i < n; i++) {
      dsu_2ecc[i] = i;
      dsu_cc[i] = i;
    }
  }

  int find_2ecc(int v) {
    if (v == -1) return -1;
    return dsu_2ecc[v] == v ? v : dsu_2ecc[v] = find_2ecc(dsu_2ecc[v]);
  }

  int find_cc(int v) {
    v = find_2ecc(v);
    return dsu_cc[v] == v ? v : dsu_cc[v] = find_cc(dsu_cc[v]);
  }

  void add_edge(int a, int b) {
    a = find_2ecc(a);
    b = find_2ecc(b);

    if (a == b) return;

    int ca = find_cc(a);
    int cb = find_cc(b);

    if (ca != cb) {
      ++bridges_cnt;
      --comp_cnt;
      if (dsu_cc_size[ca] > dsu_cc_size[cb]) {
        swap(a, b);
        swap(ca, cb);
      }
      make_root(a);
      parent[a] = dsu_cc[a] = b;
      dsu_cc_size[cb] += dsu_cc_size[a];
    } else {
      merge_path(a, b);
    }
  }

  inline bool is_bridge(int u, int v) { return find_2ecc(u) != find_2ecc(v); }

private:
  void make_root(int v) {
    v = find_2ecc(v);
    int root = v;
    int child = -1;
    while (v != -1) {
      int p = find_2ecc(parent[v]);
      parent[v] = child;
      dsu_cc[v] = root;
      child = v;
      v = p;
    }
    dsu_cc_size[root] = dsu_cc_size[child];
  }

  void merge_path(int a, int b) {
    ++lca_iteration;
    vector<int> path_a, path_b;
    int lca = -1;
    while (lca == -1) {
      if (a != -1) {
        a = find_2ecc(a);
        path_a.push_back(a);
        if (last_visit[a] == lca_iteration){
          lca = a;
          break;
        }
        last_visit[a] = lca_iteration;
        a = parent[a];
      }
      if (b != -1) {
        b = find_2ecc(b);
        path_b.push_back(b);
        if (last_visit[b] == lca_iteration) {
          lca = b;
          break;
        }
        last_visit[b] = lca_iteration;
        b = parent[b];
      }
    }

    for (auto v : path_a) {
      dsu_2ecc[v] = lca;
      if (v == lca) break;
      --bridges_cnt;
    }
    for (auto v : path_b) {
      dsu_2ecc[v] = lca;
      if (v == lca) break;
      --bridges_cnt;
    }
  }
};
