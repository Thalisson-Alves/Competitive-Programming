struct UFDS {
  vector<int> ps, sz;
  int components;

  UFDS(int n = 0) : ps(n), sz(n, 1), components(n) {
    iota(ps.begin(), ps.end(), 0);
  }

  int find(int x) { return (x == ps[x] ? x : (ps[x] = find(ps[x]))); }

  bool same(int x, int y) { return find(x) == find(y); }

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

  int add() {
    int id = (int)ps.size();
    ps.push_back(id);
    sz.push_back(1);
    ++components;
    return id;
  };
};
