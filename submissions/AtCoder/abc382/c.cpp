#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T, typename Op = function<T(T,T)>> struct SegTree {
  int size;
  vector<T> ns;
  const Op op;
  const T id = T();
  SegTree(int n, Op f = Op(), const T identity = T()) : op(f), id(identity) {
    size = 1;
    while (size < n) size <<= 1;
    ns.resize(size << 1, id);
  }
  SegTree(const vector<T> &v, Op f = Op(), const T identity = T()) : SegTree((int)v.size(), f, identity) {
    copy(v.begin(), v.end(), ns.begin() + size);
    for (int i = size - 1; i > 0; --i)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }
  T query(int i) const { return ns[i + size]; }
  T query(int l, int r) const {
    auto ml = id, mr = id;
    for (l += size, r += size; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ml = op(ml, ns[l++]);
      if (not (r & 1)) mr = op(ns[r--], mr);
    }
    return op(ml, mr);
  }
  void update(int i, T value) { set(i, op(ns[i + size], value)); }
  void set(int i, T value) {
    ns[i += size] = value;
    while (i >>= 1)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }
  template <typename F> int pos(F f) {
    int u = 1;
    if (!f(ns[u])) return -1;
    for (auto sm = id; u < size;) {
      u <<= 1;
      if (!f(op(sm, ns[u])))
        sm = op(sm, ns[u++]);
    }
    return u-size;
  }
  template <typename F> int find_right(int l, F f) {
    auto sm = id;
    l += size;
    do {
      while (!(l&1)) l >>= 1;
      if (f(op(sm, ns[l]))) {
        while (l < size) {
          l <<= 1;
          if (!f(op(sm, ns[l])))
            sm = op(sm, ns[l++]);
        }
        return l-size;
      }
      sm = op(sm, ns[l++]);
    } while ((l&-l) != l);
    return -1;
  }
  template <typename F> int find_left(int r, F f) {
    auto sm = id;
    r += size;
    do {
      while (r > 1 and (r&1)) r >>= 1;
      if (f(op(ns[r], sm))) {
        while (r < size) {
          r = r<<1|1;
          if (!f(op(ns[r], sm)))
            sm = op(ns[r--], sm);
        }
        return r-size;
      }
      sm = op(ns[r--], sm);
    } while (r&(r+1));
    return -1;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  SegTree<int> seg(a, [](int x, int y) { return min(x, y); }, INT_MAX);
  while (m--) {
    int x;
    cin >> x;
    int res = seg.pos([&](int v) { return x >= v; });
    cout << (res == -1 ? res : res + 1) << '\n';
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
