#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T, auto op, typename L, auto mapping, auto composition>
struct SegTreeLazy {
  int N, size, height;
  const T eT;
  const L eL;
  vector<T> d;
  vector<L> lz;

  SegTreeLazy(const T &eT_ = T(), const L &eL_ = L()) : SegTreeLazy(0, eT_, eL_) {}
  explicit SegTreeLazy(int n, const T &eT_ = T(), const L &eL_ = L()) : SegTreeLazy(vector<T>(n, eT_), eT_, eL_) {}
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

    d[k] = call_args<mapping>(f, d[k], fst, lst);
    if (k < size) {
      lz[k] = call_args<composition>(f, lz[k], fst, lst);
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
  constexpr static auto call_args(Tuple&& tuple, std::index_sequence<idx...>) { return f(std::get<idx>(std::forward<Tuple>(tuple))...); }
  template <auto f, typename... Args>
  constexpr static auto call_args(Args&&... tuple) { return call_args<f>(std::forward_as_tuple(std::forward<Args>(tuple)...), std::make_index_sequence<arg_count(f)()>{}); }
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

struct L {
  ll value;
  int startpos = -1, cnt = 1;
 
  constexpr inline ll first(int l) const {
    return value + (l - startpos) * cnt;
  }
};
 
inline ll sum(ll n) { return n*(n+1ll)>>1ll; }
ll mapping(L a, ll b, int l, int r) {
  if (a.startpos == -1) return b;
  auto fst = a.first(l);
  auto lst = a.first(r);
  return b + (r - l + 1) * (fst + lst) / 2;
}
 
L comp(L a, L b, int l) {
  if (a.startpos == -1) return b;
  if (b.startpos == -1) return a;
  return L(a.first(l) + b.first(l), l, a.cnt + b.cnt);
}
 
void solve()
{
  int n, q;
  cin >> n >> q;
 
  SegTreeLazy<ll, F(a + b), L, mapping, comp> st(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.set(i, x);
  }
 
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    --a, --b;
    if (t == 1) {
      st.update(a, b, L(1, a));
    } else {
      cout << st.query(a, b) << '\n';
    }
  }
}

int32_t main()
{
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
