#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

/* LiChaoTree
 *
 * Add lines (ax + b) and query maximum value at `x`.
 * If you want to get minimum value, set inf = numeric_limits<T>::max().
 * In case of overflow, try to compress `x` values.
 *
 * - query(x) -> get maximum `y` value at `x`
 *   - O(log (HI-LO))
 * - add(Line s) -> add line `s` to the tree
 *   - O(log (HI-LO))
 * - add_segment(Line s, l, r) -> add line `s` to the tree in range [l, r]
 *   - O(log^2 (HI-LO))
 */
template <typename T = ll, T LO = T(-1e9), T HI = T(1e9)> struct LiChaoTree {
  // get max value at x by default
  // to get min value, set inf = numeric_limits<T>::max()
  static constexpr T inf = numeric_limits<T>::min();
  static constexpr bool compare(T a, T b) {
    if constexpr (inf == numeric_limits<T>::max()) {
      return a < b;
    } else {
      return a > b;
    }
  }
  static constexpr T best(T a, T b) { return (compare(a, b) ? a : b); }
  struct Line {
    T a, b;
    array<int, 2> ch;
    Line(T a_ = 0, T b_ = inf) : a(a_), b(b_), ch({-1, -1}) { }
    constexpr T eval(T x) const { return a * x + b; }
    constexpr bool is_leaf() const { return ch[0] == -1 and ch[1] == -1; }
  };
  vector<Line> ln;
  LiChaoTree() { ln.emplace_back(); }
  T query(T x, int v = 0, T l = LO, T r = HI) {
    auto m = l + (r - l) / 2, val = ln[v].eval(x);
    if (ln[v].is_leaf()) return val;
    if (x <= m) return best(val, query(x, ch(v, 0), l, m));
    else return best(val, query(x, ch(v, 1), m+1, r));
  }
  void add(T a, T b) { add({a, b}, 0, LO, HI); }
  void add(Line s, int v, T l, T r) {
    auto m = l + (r - l) / 2;
    bool L = compare(s.eval(l), ln[v].eval(l));
    bool M = compare(s.eval(m), ln[v].eval(m));
    bool R = compare(s.eval(r), ln[v].eval(r));
    if (M) swap(ln[v], s), swap(ln[v].ch, s.ch);
    if (s.b == inf) return;
    if (L != M) add(s, ch(v, 0), l, m);
    else if (R != M) add(s, ch(v, 1), m+1, r);
  }
  void add_segment(T a, T b, T l, T r) { add_segment({a, b}, l, r, 0, LO, HI); }
  void add_segment(Line s, T l, T r, int v, T L, T R) {
    if (l <= L and R <= r) return add(s, v, L, R);
    auto m = L + (R - L) / 2;
    if (l <= m) add_segment(s, l, r, ch(v, 0), L, m);
    if (r > m) add_segment(s, l, r, ch(v, 1), m+1, R);
  }
private:
  int ch(int v, bool b) {
    if (ln[v].ch[b] == -1) {
      ln[v].ch[b] = (int)ln.size();
      ln.emplace_back();
    }
    return ln[v].ch[b];
  }
};

void solve() {
  int n;
  cin >> n;
  vector<array<ll, 3>> v(n);
  for (auto &[a, b, c] : v) cin >> a >> b >> c;
  sort(begin(v), end(v), [](const auto &a, const auto &b) {
    return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
  });
  {
    int i = 0;
    for (int j = 1; j < (int)size(v); j++) {
      if (v[i][0] == v[j][0] and v[i][1] == v[j][1]) v[i][2] += v[j][2];
      else v[++i] = v[j];
    }
    v.resize(i+1);
  }
  LiChaoTree<ll> cht;
  cht.add(0, 0);
  constexpr int inf = 1e9+1;
  for (auto [l, r, x] : v) {
    cht.add_segment(0, cht.query(r-1)+x, r, inf);
  }
  cout << cht.query(inf) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
