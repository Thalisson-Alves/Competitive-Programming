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

template <typename T, int K> struct KMajority {
  array<pair<T, int>, K> hist;
  KMajority() { hist.fill({T(), -1}); }
  void add(T x, int cnt) {
    assert(cnt > 0);
    for (auto &[k, c] : hist) if (~c and k == x) {
      c += cnt;
      return;
    }
    for (auto &[k, c] : hist) if (c == -1) {
      k = x, c = cnt;
      return;
    }
    for (auto &[k, c] : hist) if (c < cnt) swap(k, x), swap(c, cnt);
    for (auto &[k, c] : hist) if (!(c -= cnt)) c = -1;
  };
  void merge(const KMajority &km) {
    for (auto [x, y] : km.hist) if (~y) add(x, y);
  }
  static KMajority op(KMajority ka, const KMajority &kb) {
    ka.merge(kb);
    return ka;
  };
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<vector<int>> pos(n+1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  auto count = [&](int l, int r, int x) {
    const auto &v = pos[x];
    return upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
  };
  using T = KMajority<int, 4>;
  SegTree<T> seg([&](){
    vector<T> ini(n);
    for (int i = 0; i < n; i++) ini[i].hist[0] = {a[i], 1};
    return ini;
  }(), T::op);
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    --l, --r;
    auto mp = seg.query(l, r);
    int res = INT_MAX;
    for (auto [x, y] : mp.hist) {
      if (~y and count(l, r, x) > (r-l+1)/k)
        res = min(res, x);
    }
    cout << (res == INT_MAX ? -1 : res) << '\n';
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
