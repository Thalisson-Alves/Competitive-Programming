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
struct Node {
  int pref0, pref1, suff0, suff1, len, res;
  Node() : pref0(0), pref1(0), suff0(0), suff1(0), len(0), res(0) {}
  Node(bool x) : pref0(!x), pref1(x), suff0(!x), suff1(x), len(1), res(1) {}
};
Node op(const Node &a, const Node &b) {
  Node res;
  res.pref0 = a.pref0 + (a.pref0 == a.len ? b.pref0 : 0);
  res.pref1 = a.pref1 + (a.pref1 == a.len ? b.pref1 : 0);
  res.suff0 = b.suff0 + (b.suff0 == b.len ? a.suff0 : 0);
  res.suff1 = b.suff1 + (b.suff1 == b.len ? a.suff1 : 0);
  res.len = a.len + b.len;
  res.res = max({a.res, b.res, a.suff0+b.pref0, a.suff1+b.pref1});
  return res;
}

void solve() {
  string s;
  cin >> s;
  SegTree<Node> seg((int)size(s), op);
  for (int i = 0; i < (int)size(s); i++)
    seg.set(i, s[i]-'0');
  int q; cin >> q;
  while (q--) {
    int i;
    cin >> i;
    --i;
    s[i] = '1'-s[i]+'0';
    seg.set(i, s[i]-'0');
    cout << seg.ns[1].res << " \n"[!q];
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
