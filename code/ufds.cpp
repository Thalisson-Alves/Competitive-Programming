struct UFDS {
  vector<int> ps, sz;
  int components;

  UFDS(int n) : ps(n), sz(n, 1), components(n)
  {
    iota(all(ps), 0);
  }

  int find_set(int x)
  {
    return (x == ps[x] ? x : (ps[x] = find_set(ps[x])));
  }

  bool same_set(int x, int y)
  {
    return find_set(x) == find_set(y);
  }

  bool union_set(int x, int y)
  {
    x = find_set(x);
    y = find_set(y);
    
    if (x == y) return false;

    if (sz[x] < sz[y])
      swap(x, y);

    ps[y] = x;
    sz[x] += sz[y];

    components--;
    return true;
  }
};
