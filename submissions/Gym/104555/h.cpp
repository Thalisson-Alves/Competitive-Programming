#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

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

  void add(Line s, int v = 0, T l = LO, T r = HI) {
    auto m = l + (r - l) / 2;
    bool L = compare(s.eval(l), ln[v].eval(l));
    bool M = compare(s.eval(m), ln[v].eval(m));
    bool R = compare(s.eval(r), ln[v].eval(r));
    if (M) swap(ln[v], s), swap(ln[v].ch, s.ch);
    if (s.b == inf) return;
    if (L != M) add(s, ch(v, 0), l, m);
    else if (R != M) add(s, ch(v, 1), m+1, r);
  }

  void add_segment(Line s, T l, T r, int v = 0, T L = LO, T R = HI) {
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

void solve()
{
  int n, s;
  cin >> n >> s;
  constexpr ll MAX_X = 1e9;
  LiChaoTree<ll, 0, MAX_X> cht;
  cht.add({0, 0});

  vector<tuple<ll, ll, ll>> jobs(n);
  for (auto &[l, r, c] : jobs) cin >> l >> r >> c;
  sort(all(jobs));

  ll res = 0;
  for (auto [l, r, c] : jobs) {
    cht.add_segment({s, -s * (l - 1) - c + cht.query(l-1)}, l, r);
    cht.add_segment({0, cht.query(r)}, r, MAX_X);
    res = max(res, cht.query(r));
  }
  cout << res << '\n';
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
