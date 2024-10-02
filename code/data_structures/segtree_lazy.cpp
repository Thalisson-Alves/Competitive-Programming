#define SegTree SegTreeLazy<Node, op, Lazy, mapping, composition>
template <typename T, auto op, typename L, auto mapping, auto composition>
struct SegTreeLazy {
  int N, size, height;
  const T eT;
  const L eL;
  vector<T> d;
  vector<L> lz;
  vector<pair<int, int>> lrs;
  SegTreeLazy(int n=0, const T &eT_ = T(), const L &eL_ = L()) : SegTreeLazy(vector<T>(n, eT_), eT_, eL_) {}
  SegTreeLazy(const vector<T>& v, const T &eT_ = T(), const L &eL_ = L()) : N(int(v.size())), eT(eT_), eL(eL_) {
    size = 1; height = 0;
    while (size < N) size<<=1, height++;
    d = vector<T>(2 * size, eT);
    lz = vector<L>(size, eL);
    lrs.resize(2 * size);
    for (int i = 0; i < N; i++) {
      d[size + i] = v[i];
      lrs[size + i] = {i, i};
    }
    for (int i = N; i < size; i++) lrs[size + i] = {i, i};
    for (int i = size - 1; i >= 1; i--) {
      update(i);
      lrs[i] = {lrs[i << 1].first, lrs[i << 1 | 1].second};
    }
  }
  T get(int p) {
    assert(0 <= p && p < N);
    p += size;
    for (int i = height; i >= 1; i--) push(p >> i);
    return d[p];
  }
  void set(int p, T x) {
    assert(0 <= p && p < N);
    p += size;
    for (int i = height; i >= 1; i--) push(p >> i);
    d[p] = x;
    for (int i = 1; i <= height; i++) update(p >> i);
  }
  void update(int p, L f) {
    assert(0 <= p && p < N);
    p += size;
    for (int i = height; i >= 1; i--) push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= height; i++) update(p >> i);
  }
  T query_all() { return d[1]; }
  T query(int l, int r) {
    assert(0 <= l && l <= r && r < N);
    l += size;
    r += size;
    for (int i = height; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if ((((r+1) >> i) << i) != (r+1)) push(r >> i);
    }
    T sml = eT, smr = eT;
    while (l <= r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (!(r & 1)) smr = op(d[r--], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }
  void update(int l, int r, L f) {
    assert(0 <= l && l <= r && r < N);
    l += size;
    r += size;
    for (int i = height; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if ((((r+1) >> i) << i) != (r+1)) push(r >> i);
    }
    int l2 = l, r2 = r;
    while (l <= r) {
      if (l & 1) all_apply(l++, f);
      if (!(r & 1)) all_apply(r--, f);
      l >>= 1;
      r >>= 1;
    }
    l = l2;
    r = r2;
    for (int i = 1; i <= height; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if ((((r+1) >> i) << i) != (r+1)) update(r >> i);
    }
  }
  template <typename F> int pos(F f) {
    int u = 1;
    if (!f(d[u])) return -1;
    for (auto sm = eT; u < size;) {
      push(u);
      u <<= 1;
      if (!f(op(sm, d[u])))
        sm = op(sm, d[u++]);
    }
    return u-size;
  }
  template <typename F> int find_right(int l, F f) {
    assert(0 <= l and l <= N);
    l += size;
    for (int i = height; i >= 1; i--) push(l >> i);
    auto sm = eT;
    do {
      while (!(l&1)) l >>= 1;
      if (f(op(sm, d[l]))) {
        while (l < size) {
          push(l);
          l <<= 1;
          if (f(op(sm, d[l])))
            sm = op(sm, d[l++]);
        }
        return l-size;
      }
      sm = op(sm, d[l++]);
    } while ((l&-l) != l);
    return -1;
  };
  template <typename F> int find_left(int r, F f) {
    assert(0 <= r and r <= N);
    r += size;
    for (int i = height; i >= 1; i--) push(r >> i);
    auto sm = eT;
    do {
      while (r > 1 and (r&1)) r >>= 1;
      if (f(op(d[r], sm))) {
        while (r < size) {
          push(r);
          r = r<<1|1;
          if (f(op(d[r], sm)))
            sm = op(d[r--], sm);
        }
        return r-size;
      }
      sm = op(d[r--], sm);
    } while ((r&-r) != r);
    return -1;
  };
private:
  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, L f) {
    d[k] = mapping(f, d[k], lrs[k]);
    if (k < size) lz[k] = composition(f, lz[k], lrs[k]);
  }
  void push(int k) {
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = eL;
  }
  static_assert(is_convertible_v<decltype(op), function<T(T, T)>>, "op must be a function T(T, T)");
  static_assert(is_convertible_v<decltype(mapping), function<T(L, T, pair<int, int>)>>, "mapping must be a function T(L, T, lr)");
  static_assert(is_convertible_v<decltype(composition), function<L(L, L, pair<int, int>)>>, "composition must be a function L(L, L, lr)");
};
struct Node {};
Node op(Node a, Node b) {}
struct Lazy {};
Node mapping(Lazy f, Node x, [[maybe_unused]] pair<int, int> lr) {}
Lazy composition(Lazy f, Lazy g, [[maybe_unused]] pair<int, int> lr) {}
