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
    T eval(T x) { return a * x + b; }
  };
  vector<Line> ln;
  LiChaoTree() { ln.emplace_back(); }

  T query(T x, int v = 0, T l = LO, T r = HI) {
    auto m = l + (r - l) / 2, val = ln[v].eval(x);
    if (val == inf) return val;
    if (x < m) return best(val, query(x, ch(v, 0), l, m-1));
    else return best(val, query(x, ch(v, 1), m+1, r));
  }

  void add(Line s, int v = 0, T l = LO, T r = HI) {
    auto m = l + (r - l) / 2;
    bool L = compare(s.eval(l), ln[v].eval(l));
    bool M = compare(s.eval(m), ln[v].eval(m));
    bool R = compare(s.eval(r), ln[v].eval(r));
    if (M) swap(ln[v], s), swap(ln[v].ch, s.ch);
    if (s.b == inf) return;
    if (L != M) add(s, ch(v, 0), l, m-1);
    else if (R != M) add(s, ch(v, 1), m+1, r);
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
