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
  SegTree(const vector<T> &v, Op f, const T identity) : SegTree((int)v.size(), f, identity) {
    copy(v.begin(), v.end(), ns.begin() + size);
    for (int i = size - 1; i > 0; --i)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }
  SegTree(const vector<T> &v, Op f) : SegTree(v, f, T()) {}
  SegTree(const vector<T> &v, const T identity = T()) : SegTree(v, Op(), identity) {}

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
  constexpr int mod = 1e9+7;
  struct Node {
    int d[2][2];
    Node() { d[0][0]=1,d[0][1]=0,d[1][0]=0,d[1][1]=1; }
    Node(char c) {
      if (c == '?') d[0][0]=19,d[0][1]=7,d[1][0]=6,d[1][1]=20;
      else if (c == 'H') d[0][0]=1,d[0][1]=0,d[1][0]=1,d[1][1]=0;
      else if (c=='S'||c=='D') d[0][0]=0,d[0][1]=1,d[1][0]=0,d[1][1]=1;
      else if (string_view("AEIOU").find(c)!=string::npos) d[0][0]=0,d[0][1]=1,d[1][0]=1,d[1][1]=0;
      else d[0][0]=1,d[0][1]=0,d[1][0]=0,d[1][1]=1;
    }
    Node operator*(const Node &o) const {
      Node res;
      res.d[0][0]=res.d[1][1]=0;
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          for (int k = 0; k < 2; k++) {
            (res.d[i][j] += (ll)d[i][k]*o.d[k][j]%mod) %= mod;
          }
        }
      }
      return res;
    }
  };
  vector<Node> ini;
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    ini.emplace_back(c);
  }
  SegTree<Node, multiplies<>> seg(ini);
  while (q--) {
    cout << seg.ns[1].d[0][0] << '\n';
    int i; char c;
    cin >> i >> c;
    seg.set(--i, Node(c));
  }
  cout << seg.ns[1].d[0][0] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
