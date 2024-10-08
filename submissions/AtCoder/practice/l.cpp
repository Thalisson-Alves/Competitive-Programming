#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

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
    for (int i = size - 1; i >= 1; i--) {
      update(i);
      lrs[i] = {lrs[i << 1].first, lrs[i << 1 | 1].second};
    }
  }
  void set(int p, T x) {
    assert(0 <= p && p < N);
    p += size;
    for (int i = height; i >= 1; i--) push(p >> i);
    d[p] = x;
    for (int i = 1; i <= height; i++) update(p >> i);
  }
  T get(int p) {
    assert(0 <= p && p < N);
    p += size;
    for (int i = height; i >= 1; i--) push(p >> i);
    return d[p];
  }
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
  T query_all() { return d[1]; }
  void update(int p, L f) {
    assert(0 <= p && p < N);
    p += size;
    for (int i = height; i >= 1; i--) push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= height; i++) update(p >> i);
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

constexpr ll mod = 998244353;

using Node = ll;
Node op(Node a, Node b) {
  return (a + b) % mod;
}
struct Lazy {
  ll b = 1, c;
};
Node mapping(Lazy f, Node x, [[maybe_unused]] pair<int, int> lr) {
  return (f.b*x%mod+(lr.second-lr.first+1)*f.c%mod)%mod;
}
Lazy composition(Lazy f, Lazy g, [[maybe_unused]] pair<int, int> lr) {
  return {f.b*g.b%mod, (f.b*g.c%mod+f.c)%mod};
}

void solve() {
  int n, q;
  cin >> n >> q;
  SegTree seg(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    seg.set(i, x);
  }
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    --r;
    if (t) {
      cout << seg.query(l, r) << '\n';
    } else {
      int b, c;
      cin >> b >> c;
      seg.update(l, r, {b, c});
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
