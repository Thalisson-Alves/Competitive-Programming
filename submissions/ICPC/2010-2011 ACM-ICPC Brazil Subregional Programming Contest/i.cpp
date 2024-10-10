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
  if constexpr (is_floating_point_v<T>) return fabs(a - b) <= EPS;
  else return a == b;
}

const double PI = acos(-1);
double to_rad(double deg) { return deg * PI / 180; }
double to_deg(double rad) { return rad * 180 / PI; }

template<typename T=double> struct Point {
  T x, y;

  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}

  inline Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  inline Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  inline Point operator+(const T &k) const { return Point(x + k, y + k); }
  inline Point operator-(const T &k) const { return Point(x - k, y - k); }
  inline Point operator*(const T &k) const { return Point(x * k, y * k); }
  inline Point operator/(const T &k) const { return Point(x / k, y / k); }

  inline Point& operator+=(const Point &p) { x += p.x, y += p.y; return *this; }
  inline Point& operator-=(const Point &p) { x -= p.x, y -= p.y; return *this; }
  inline Point& operator+=(const T &k) { x += k, y += k; return *this; }
  inline Point& operator-=(const T &k) { x -= k, y -= k; return *this; }
  inline Point& operator*=(const T &k) { x *= k, y *= k; return *this; }
  inline Point& operator/=(const T &k) { x /= k, y /= k; return *this; }

  inline bool operator==(const Point &p) const { return eq(x, p.x) and eq(y, p.y); }
  inline bool operator!=(const Point &p) const { return !eq(x, p.x) or !eq(y, p.y); }
  inline bool operator<(const Point &p) const { return eq(x, p.x) ? y < p.y : x < p.x; }
  inline bool operator>(const Point &p) const { return eq(x, p.x) ? y > p.y : x > p.x; }
  inline bool operator<=(const Point &p) const { return *this == p or *this < p; }
  inline bool operator>=(const Point &p) const { return *this == p or *this > p; }

  friend ostream& operator<<(ostream &os, const Point &p) { return os << p.x << ' ' << p.y; }
  friend istream& operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }

  template<typename U> void rotate(U rad) {
    tie(x, y) = make_pair(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
  }
  template<typename U> Point<U> rotated(U rad) const {
    return Point<U>(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
  }
  inline T dot(const Point &p) const { return x * p.x + y * p.y; }
  inline T cross(const Point &p) const { return x * p.y - y * p.x; }
  inline T cross(const Point &a, const Point &b) const { return (a - *this).cross(b - *this); }
  inline T dist2() const { return x * x + y * y; }
  inline double dist() const { return hypot(x, y); }
  inline double angle() const { return atan2(y, x); }
  inline double norm() const { return sqrt(dot(*this)); }
  inline Point rot90() const { return Point(-y, x); }
  inline Point to(const Point &p) const { return p - *this; }
};

/* Orientation of point `p` relative to line `a-b`
 *
 * Returns:
 * -1: `p` is to the right of the line passing through `a` and `b`
 *  0: `p` belongs to the line passing through `a` and `b`
 *  1: `p` is to the left of the line passing through `a` and `b`
 */
template<typename T> int orientation(const Point<T> &p, const Point<T> &a, const Point<T> &b) {
  auto x = a.x*(b.y-p.y)+b.x*(p.y-a.y)+p.x*(a.y-b.y);
  bool is_zero = false;
  if constexpr (is_floating_point<T>())
    is_zero = feq(x, 0.0);
  else
    is_zero = x == 0;

  if (is_zero) return 0;
  return (x < 0 ? -1 : 1);
}

template<typename T> bool collinear(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
  return feq(orientation(a, b, c), 0.0);
}

template<const bool include_collinear=false, typename T> bool cw(const Point<T> &p, const Point<T> &a, const Point<T> &b) {
  auto o = orientation(p, a, b);
  if constexpr (include_collinear)
    return o <= 0;
  else
    return o < 0;
}

template<const bool include_collinear=false, typename T> bool ccw(const Point<T> &p, const Point<T> &a, const Point<T> &b) {
  auto o = orientation(p, a, b);
  if constexpr (include_collinear)
    return o >= 0;
  else
    return o > 0;
}

/* Check if point p is inside triangle v1, v2, v3 */
template <typename Pt> bool is_inside_triangle(const Pt &p, const Pt &v1, const Pt &v2, const Pt &v3) {
  auto o1 = orientation(p, v1, v2);
  auto o2 = orientation(p, v2, v3);
  auto o3 = orientation(p, v3, v1);

  bool neg = (o1 < 0) or (o2 < 0) or (o3 < 0);
  bool pos = (o1 > 0) or (o2 > 0) or (o3 > 0);
  return !neg or !pos;
}

/* Check if point p is inside a convex polygon
 *
 * Points i and i+1 must represent a segment of the polygon
 *
 * Time complexity: O(log n)
*/
template <typename Pt> bool is_inside_polygon(const vector<Pt> &poly, const Pt &p) {
  int l = 2, r = (int)poly.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ccw<true>(p, poly[0], poly[mid]))
      l = mid + 1;
    else
      r = mid - 1;
  }

  return is_inside_triangle(p, poly[0], poly[r-1], poly[r]);
}

template <typename T = double> struct Line {
  T a, b, c; // ax + by = c

  Line() : a(0), b(0), c(0) {}
  Line(T a_, T b_, T c_) : a(a_), b(b_), c(c_) {}
  Line(const Point<T> &p, const Point<T> &q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = p.cross(q);
  }

  bool operator==(const Line &l) const {
    return eq(a, l.a) and eq(b, l.b) and eq(c, l.c);
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

  inline bool operator==(const Segment &l) const {
    return p == l.p and q == l.q;
  }

  inline bool parallel(const Segment &l) const {
    // TODO: handle zero length segments
    return eq(p.cross(q, l.p), (T)0) and eq(p.cross(q, l.q), (T)0);
  }

  inline bool intersects(const Segment &l) const {
    if (parallel(l)) {
      return intersects(l.p) or intersects(l.q) or l.intersects(p) or
             l.intersects(q);
    }
    return orientation(p, q, l.p) * orientation(p, q, l.q) <= 0 and
           orientation(l.p, l.q, p) * orientation(l.p, l.q, q) <= 0;
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

  inline Point<T> closest(const Point<T> &r) const {
    if ((r - p).dot(q - p) < EPS) return p;
    if ((r - q).dot(p - q) < EPS) return q;

    return p + (q - p) * ((r - p).dot(q - p) / (q - p).dist2());
  }

  inline double dist2(const Point<T> &r) const { return (r-closest(r)).dist2(); }
  inline double dist(const Point<T> &r) const { return sqrt(dist2(r)); }

  bool operator<(const Segment &l) const {
    if (p.x < l.p.x) return p.to(q).cross(p.to(l.p)) < 0;
    else return l.p.to(l.q).cross(l.p.to(p)) > 0;
  }

  friend ostream& operator<<(ostream &os, const Segment &l) { return os << l.p << ' ' << l.q; }
  friend istream& operator>>(istream &is, Segment &l) { return is >> l.p >> l.q; }
};

void solve() {
  for (int t, m, c; cin >> t >> m >> c;) {
    vector<Segment<int>> segs(m);
    for (auto &x : segs) cin >> x;
    vector<Point<int>> tps(c);
    for (auto &x : tps) cin >> x;
    sort(tps.begin(), tps.end());

    vector<Point<int>> all;
    all.reserve(segs.size() * 2 + tps.size() + 2);
    cin >> all.emplace_back() >> all.emplace_back();

    for (auto &[a, b] : segs) {
      all.push_back(a);
      all.push_back(b);
    }
    for (auto &x : tps)
      all.push_back(x);

    auto cost = [&](int i, int j) {
      if (binary_search(tps.begin(), tps.end(), all[i]) and binary_search(tps.begin(), tps.end(), all[j]))
        return 0.0;
      auto dif = all[i] - all[j];
      return hypot(dif.x, dif.y);
    };

    auto can = [&](int i, int j, bool is_tp) {
      Segment<int> s(all[i], all[j]);
      for (auto &x : segs) {
        auto inter = s.intersection(x);
        if (!inter) inter = x.intersection(s);
        if (inter) {
          if (is_tp) return false;
          if (inter->p != inter->q) continue;
          if (s.p == x.p or s.q == x.p or s.p == x.q or s.q == x.q) continue;
          return false;
        }
      }
      return true;
    };

    vector<vector<pair<int, double>>> g(all.size());
    for (int i = 0; i < (int)all.size(); i++) {
      for (int j = 0; j < (int)all.size(); j++) {
        if (i == j) continue;
        auto w = cost(i, j);
        if (can(i, j, eq(w, 0.0))) {
          g[i].emplace_back(j, w);
          g[j].emplace_back(i, w);
        }
      }
    }

    auto res = [&](int s, int f) { // disjktra
      vector<double> dist(g.size(), numeric_limits<double>::max());
      dist[s] = 0;
      using T = tuple<double, int, int>;
      priority_queue<T, vector<T>, greater<T>> pq;
      pq.emplace(0, 0, s);
      while (not pq.empty()) {
        auto [du, tp, u] = pq.top(); pq.pop();
        if (!eq(du, dist[u])) continue;

        for (auto [v, w] : g[u]) {
          if (dist[v] > dist[u] + w and (!eq(w, 0.) or tp < t)) {
            dist[v] = dist[u] + w;
            pq.emplace(dist[u] + w, tp + eq(w, 0.), v);
          }
        }
      }

      return dist[f];
    }(0, 1);

    cout << fixed << setprecision(1) << res << '\n';
  }
}

// clang-format off
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
