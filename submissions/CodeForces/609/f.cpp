#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T, typename Op = T(*)(T,T)> struct SegTree {
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
    } while ((r&-r) != r);
    return -1;
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<pair<int, ll>> frog(n);
  unordered_map<int, int> ids;
  vector<pair<int, ll>> res(n);
  for (int i = 0; i < n; i++) {
    cin >> frog[i].first >> frog[i].second;
    ids[frog[i].first] = i;
    res[i].second = frog[i].second;
  }
  sort(begin(frog), end(frog));
  SegTree seg(frog, F(a.first+a.second>b.first+b.second?a:b), {0,-1});
  multiset<pair<int, int>> st;
  while (q--) {
    int a, b;
    cin >> a >> b;
    auto it = st.emplace(a, b);
    while (it != end(st)) {
      int pos = seg.pos([&](const auto &x) { return x.first+x.second>=it->first; });
      if (pos == -1) break;
      auto cur = seg.query(pos);
      if (cur.first > it->first) break;
      seg.set(pos, {cur.first, cur.second + it->second});
      auto &[r1, r2] = res[ids[cur.first]];
      ++r1, r2 += it->second;
      st.erase(it++);
    }
  }
  for (auto [a, b] : res) cout << a << ' ' << b << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
