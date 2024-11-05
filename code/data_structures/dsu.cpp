struct DSU {
  vector<int> ps, sz;
  int comp;
  DSU(int n = 0) : ps(n, -1), sz(n, 1), comp(n) {}
  int find(int x) { return (~ps[x] ? (ps[x] = find(ps[x])) : x); }
  bool same(int x, int y) { return find(x) == find(y); }
  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    ps[y] = x;
    sz[x] += sz[y];
    --comp;
    return true;
  }
  int add() {
    int id = (int)ps.size();
    ps.push_back(id);
    sz.push_back(1);
    ++comp;
    return id;
  };
};
