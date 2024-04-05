#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

constexpr double EPS = 1e-9;
template <typename T> bool eq(const T a, const T b) {
  if constexpr (is_floating_point_v<T>)
    return fabs(a - b) <= EPS;
  else
    return a == b;
}

template <typename T = double> struct Point {
  T x, y;

  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}

  inline Point operator-(const Point &p) const {
    return Point(x - p.x, y - p.y);
  }

  inline Point &operator+=(const Point &p) {
    x += p.x, y += p.y;
    return *this;
  }

  inline bool operator==(const Point &p) const {
    return eq(x, p.x) and eq(y, p.y);
  }
  inline bool operator<(const Point &p) const {
    return eq(x, p.x) ? y < p.y : x < p.x;
  }
  inline bool operator<=(const Point &p) const {
    return *this == p or *this < p;
  }

  inline T cross(const Point &p) const { return x * p.y - y * p.x; }
  inline T cross(const Point &a, const Point &b) const {
    return (a - *this).cross(b - *this);
  }
};

template <typename T = double> struct Line {
  T a, b, c; // ax + by = c

  Line() : a(0), b(0), c(0) {}
  Line(T a_, T b_, T c_) : a(a_), b(b_), c(c_) {}
  Line(const Point<T> &p, const Point<T> &q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = p.cross(q);
  }

  bool parallel(const Line &l) const { return eq(a * l.b, b * l.a); }

  optional<Point<T>> intersection(const Line &l) const {
    if (parallel(l))
      return {};
    auto det = a * l.b - b * l.a;
    return Point<T>((b * l.c - c * l.b) / det, (c * l.a - a * l.c) / det);
  }
};

template <typename T = double> struct Segment {
  Point<T> p, q;

  Segment() : p(), q() {}
  Segment(Point<T> a_, Point<T> b_) : p(a_), q(b_) {}

  inline bool parallel(const Segment &l) const {
    return eq(p.cross(q, l.p), (T)0) and eq(p.cross(q, l.q), (T)0);
  }

  inline bool intersects(const Segment &l) const {
    if (parallel(l)) {
      return intersects(l.p) or intersects(l.q) or l.intersects(p) or
             l.intersects(q);
    }
    return (p.cross(q, l.p) * p.cross(q, l.q) <= 0) and
           (l.p.cross(l.q, p) * l.p.cross(l.q, q) <= 0);
  }

  inline bool intersects(const Point<T> &r) const {
    return eq(p.cross(q, r), (T)0) and min(p, q) <= r and r <= max(p, q);
  }
  optional<Point<T>> intersection(const Point<T> &r) const {
    if (intersects(r))
      return r;
    return {};
  }

  inline optional<Segment<T>> intersection(const Segment &l) const {
    if (!intersects(l))
      return {};
    if (parallel(l)) {
      return Segment(max(min(p, q), min(l.p, l.q)),
                     min(max(p, q), max(l.p, l.q)));
    }
    if (auto pt = Line<T>(p, q).intersection(Line<T>(l.p, l.q)))
      return Segment(*pt, *pt);
    return {};
  }

  bool operator<(const Segment &l) const {
    return minmax(p, q) < minmax(l.p, l.q);
  }
};

void solve() {
  int n;
  cin >> n;
  using seg = Segment<ll>;
  using pt = Point<ll>;
  constexpr auto read_coords = []() {
    int x, y, d;
    cin >> x >> y >> d;
    seg A({x - d, y}, {x, y + d});
    seg B({x, y + d}, {x + d, y});
    seg D({x + d, y}, {x, y - d});
    seg C({x, y - d}, {x - d, y});
    return set<seg>({A, B, C, D});
  };
  constexpr auto sign = [](auto x) -> int { return (x < 0 ? -1 : x > 0); };
  auto coords = read_coords();
  for (int k = 0; k < n - 1; k++) {
    auto cs = read_coords();
    set<seg> nxt;
    for (const auto &i : coords) {
      for (const auto &j : cs) {
        if (auto x = i.intersection(j)) {
          nxt.insert(*x);
        }
      }
    }
    coords = nxt;
  }

  set<pt> res;
  for (const auto &c : coords) {
    auto [s, t] = c;
    for (pt delta = {sign(t.x - s.x), sign(t.y - s.y)}; s != t; s += delta)
      res.insert(s);
    res.insert(t);
  }

  for (const auto [x, y] : res)
    cout << x << ' ' << y << '\n';
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
