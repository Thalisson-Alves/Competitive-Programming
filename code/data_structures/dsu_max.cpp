/* DSU with max edge weight in path between two nodes
 * - int find(int x): returns the representative of the set containing x
 * - bool same(int x, int y): returns whether x and y are in the same set
 * - bool join(int x, int y, T w): joins the sets containing x and y with weight w
 * - T query(int u, int v): returns the maximum edge weight in the path between u and v
 * - int add(): adds a new element to the DSU
 *
 * Time complexity: O(log(n))
 */
template<typename T=ll> struct DSU {
  vector<pair<int, T>> ps;
  vector<int> sz;
  int comp;
  DSU(int n = 0) : ps(n, {-1, -1}), sz(n, 1), comp(n) {}
  int find(int x) { return (~ps[x].first ? find(ps[x].first) : x); }
  bool same(int x, int y) { return find(x) == find(y); }
  bool join(int x, int y, T w) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    ps[y] = {x, w};
    sz[x] += sz[y];
    --comp;
    return true;
  }
  T query(int u, int v) const {
    T res = numeric_limits<T>::min();
    while (u != v) {
      auto &p = sz[u] < sz[v] ? u : v;
      res = max(res, ps[p].second);
      p = ps[p].first;
    }
    return res;
  }
  int add() {
    int id = (int)ps.size();
    ps.emplace_back(-1, -1);
    sz.push_back(1);
    ++comp;
    return id;
  };
};
