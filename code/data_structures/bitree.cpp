template<typename T> struct BITree {
  int N;
  vector<T> v;

  BITree(int n) : N(n), v(n+2, 0) {}

  void update(int i, T x) {
    for (++i; i <= N; i += i & -i)
      v[i] += x;
  }

  void update(int l, int r, T x) {
    update(l, x);
    update(r+1, -x);
  }

  T query(int i, int j) { return query(j) - query(i - 1); }

  T query(int i) {
    T sum = 0;
    for (++i; i > 0; i -= i & -i)
      sum += v[i];
    return sum;
  }
};
