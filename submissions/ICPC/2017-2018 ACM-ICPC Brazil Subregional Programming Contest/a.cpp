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

  explicit SegTreeLazy(int n=0, const T &eT_ = T(), const L &eL_ = L()) : SegTreeLazy(vector<T>(n, eT_), eT_, eL_) {}
  explicit SegTreeLazy(const vector<T>& v, const T &eT_ = T(), const L &eL_ = L()) : N(int(v.size())), eT(eT_), eL(eL_) {
    size = 1; height = 0;
    while (size < N) size<<=1, height++;
    d = vector<T>(2 * size, eT);
    lz = vector<L>(size, eL);
    for (int i = 0; i < N; i++) d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
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

    {
      int l2 = l, r2 = r;
      while (l <= r) {
        if (l & 1) all_apply(l++, f);
        if (!(r & 1)) all_apply(r--, f);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= height; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if ((((r+1) >> i) << i) != (r+1)) update(r >> i);
    }
  }
  pair<int, int> node_range(int k) const {
    int remain = height;
    for (int kk = k; kk>>=1; --remain);
    int fst = k << remain;
    int lst = min(fst + (1 << remain) - 1, size + N - 1);
    return {fst - size, lst - size};
  }

private:
  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, L f) {
    auto [fst, lst] = [&]() {
      if constexpr (decltype(arg_count(mapping))() + decltype(arg_count(composition))() > 4)
        return node_range(k);
      else
        return make_pair(0, 0);
    }();

    d[k] = arg_dispatch<mapping>(f, d[k], fst, lst);
    if (k < size) {
      lz[k] = arg_dispatch<composition>(f, lz[k], fst, lst);
    }
  }
  void push(int k) {
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = eL;
  }

  template <typename R, typename ... Types>
  constexpr static std::integral_constant<unsigned, sizeof ...(Types)> arg_count( R(*)(Types ...)) { return std::integral_constant<unsigned, sizeof ...(Types)>{}; }
  template <auto f, typename Tuple, size_t... idx>
  constexpr static auto arg_dispatch(Tuple&& tuple, std::index_sequence<idx...>) { return f(std::get<idx>(std::forward<Tuple>(tuple))...); }
  template <auto f, typename... Args>
  constexpr static auto arg_dispatch(Args&&... tuple) { return arg_dispatch<f>(std::forward_as_tuple(std::forward<Args>(tuple)...), std::make_index_sequence<arg_count(f)()>{}); }
  static_assert(is_convertible_v<decltype(op), function<T(T, T)>>, "op must be a function T(T, T)");
  static_assert(is_convertible_v<decltype(mapping), function<T(L, T)>> or
                is_convertible_v<decltype(mapping), function<T(L, T, int)>> or
                is_convertible_v<decltype(mapping), function<T(L, T, int, int)>>,
                "mapping must be a function T(L, T) or T(L, T, int, int)");
  static_assert(is_convertible_v<decltype(composition), function<L(L, L)>> or
                is_convertible_v<decltype(composition), function<L(L, L, int)>> or
                is_convertible_v<decltype(composition), function<L(L, L, int, int)>>,
                "composition must be a function L(L, L) or L(L, L, int, int)");
};

using Node = array<int, 9>;

Node op(const Node &a, const Node &b) {
  auto res = a;
  for (int i = 0; i < 9; i++)
    res[i] += b[i];
  return res;
}

using Lazy = int;

Node mapping(Lazy f, const Node &x) {
  auto res = x;
  for (int i = 0; i < 9; i++) {
    res[(f + i) % 9] = x[i];
  }
  return res;
}

Lazy composition(Lazy f, Lazy g) {
  return (f + g) % 9;
}

void solve() {
  int n, q;
  cin >> n >> q;

  Node id; id.fill(0);
  SegTree seg(n, id);
  id[1] = 1;
  for (int i = 0; i < n; i++) {
    seg.set(i, id);
  }
  constexpr auto best = [](const Node &x) {
    int res = 0;
    for (int i = 1; i < 9; i++) {
      if (x[res] <= x[i])
        res = i;
    }
    return res;
  };
  while (q--) {
    int a, b;
    cin >> a >> b;
    seg.update(a, b, best(seg.query(a, b)));
  }
  for (int i = 0; i < n; i++) {
    cout << best(seg.get(i)) << '\n';
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
