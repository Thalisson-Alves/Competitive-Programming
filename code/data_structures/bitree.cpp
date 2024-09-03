template<typename T> struct BITree {
  vector<T> v;
  BITree(int n) : v(n) {}
  void update(int i, T x) {
    assert(0 <= i and i < (int)size(v));
    for (++i; i <= (int)size(v); i+=i&-i) v[i-1] += x;
  }
  T query(int l, int r) {
    assert(0 <= l and l <= r and r <= (int)size(v));
    return query(r) - query(l);
  }
  T query(int r) {
    T res = 0;
    for (; r; r-=r&-r) res += v[r-1];
    return res;
  }
};
