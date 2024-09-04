#include <bits/stdc++.h>
#include <iomanip>
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
template<typename T=double> struct Point {
  T x, y;
  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}
  template <typename U> operator Point<U>() { return {(U)x, (U)y}; }
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  Point operator+(const T &k) const { return Point(x + k, y + k); }
  Point operator-(const T &k) const { return Point(x - k, y - k); }
  Point operator*(const T &k) const { return Point(x * k, y * k); }
  Point operator/(const T &k) const { return Point(x / k, y / k); }
  Point& operator+=(const Point &p) { x += p.x, y += p.y; return *this; }
  Point& operator-=(const Point &p) { x -= p.x, y -= p.y; return *this; }
  Point& operator+=(const T &k) { x += k, y += k; return *this; }
  Point& operator-=(const T &k) { x -= k, y -= k; return *this; }
  Point& operator*=(const T &k) { x *= k, y *= k; return *this; }
  Point& operator/=(const T &k) { x /= k, y /= k; return *this; }
  bool operator==(const Point &p) const { return eq(x, p.x) and eq(y, p.y); }
  bool operator<(const Point &p) const { return eq(x, p.x) ? y < p.y : x < p.x; }
  bool operator>(const Point &p) const { return eq(x, p.x) ? y > p.y : x > p.x; }
  bool operator<=(const Point &p) const { return *this == p or *this < p; }
  bool operator>=(const Point &p) const { return *this == p or *this > p; }
  friend ostream& operator<<(ostream &os, const Point &p) { return os << p.x << ' ' << p.y; }
  friend istream& operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }
  template<typename U> void rotate(U rad) {
    tie(x, y) = make_pair(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
  }
  template<typename U> Point<U> rotated(U rad) const {
    return Point<U>(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
  }
  T dot(const Point &p) const { return x * p.x + y * p.y; }
  T cross(const Point &p) const { return x * p.y - y * p.x; }
  T cross(const Point &a, const Point &b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  double dist() const { return hypot(x, y); }
  double dist(const Point &p) const { return to(p).dist(); }
  double angle() const { return atan2(y, x); }
  double norm() const { return sqrt(dot(*this)); }
  Point rot90() const { return Point(-y, x); }
  Point to(const Point &p) const { return p - *this; }
};

template <typename T>
T projection_len(const Point<T> &p, const Point<T> &a, const Point<T> &b) {
  return (p-a).dot(b-a) / (b-a).norm();
}

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
  if constexpr (is_floating_point<T>()) is_zero = eq(x, 0.0);
  else is_zero = x == 0;
  if (is_zero) return 0;
  return (x < 0 ? -1 : 1);
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
  double eval(T x) const { return (c-a*x)/b; }
  double dist(const Point<T> &p) const { return abs(a*p.x+b*p.y+c)/(sqrt(a*a+b*b)); }
  bool parallel(const Line &l) const { return eq(a * l.b, b * l.a); }
  optional<Point<T>> intersection(const Line &l) const {
    if (parallel(l)) return {};
    auto det = a * l.b - b * l.a;
    return Point<T>((b * l.c - c * l.b) / det, (c * l.a - a * l.c) / det);
  }
  bool operator==(const Line &l) const { return eq(a, l.a) and eq(b, l.b) and eq(c, l.c); }
};

template<typename T> using Polygon = vector<Point<T>>;

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
template <typename T> bool inside_convex(const Polygon<T> &poly, const Point<T> &p) {
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

template<typename T> int inside_simple(const Polygon<T> &poly, const Point<T> &p) {
  int w = 0;
  for (int i = 0; i < (int)size(poly); i++) {
    if (p == poly[i]) return 0;
    int j = (i+1)%size(poly);
    if (poly[i].y == p.y && poly[j].y == p.y) {
      if (min(poly[i].x, poly[j].x) <= p.x && p.x <= max(poly[i].x, poly[j].x))
        return 0;
    } else {
      bool ibelow = poly[i].y < p.y;
      bool jbelow = poly[j].y < p.y;
      if (ibelow != jbelow) {
        auto o = orientation(p, poly[i], poly[j]);
        if (o == 0) return 0;
        if (ibelow == (o > 0)) w += (ibelow ? +1 : -1);
      }
    }
  }
  return (w ? 1 : -1);
}
template<typename T> double sarea(const Polygon<T> &poly) {
  int n = (int)size(poly);
  double total = 0;
  for (int i = 0; i < n; i++) {
    total += poly[i].x * poly[(i+1)%n].y;
    total -= poly[i].y * poly[(i+1)%n].x;
  }
  return total/2;
}
template <typename T> double area(const Polygon<T> &poly) { return abs(sarea(poly)); }
template <typename T> bool is_clockwise(const Polygon<T> &poly) { return sarea(poly) < 0; }
/* Length of the common part of a polygon (poly) and a line (a-b)
 *
 * Time complexity: O(n)
 */
template<typename T> T polygon_cut_length(const Polygon<T> &poly, const Point<T> &a, const Point<T> &b) {
  Line<T> l(a, b);
  T res = 0;
  for (int i = 0; i < (int)size(poly); i++) {
    int j = (i+1)%(int)size(poly);
    int si = orientation(poly[i], a, b);
    int sj = orientation(poly[j], a, b);
    if (eq(si, 0) and eq(sj, 0)) {
      if ((b-a).dot(poly[j]-poly[i]) > 0) {
        res += projection_len(poly[j], a, b);
        res -= projection_len(poly[i], a, b);
      }
    } else if (si <= 0 && sj > 0) {
      res -= projection_len(*l.intersection({poly[i], poly[j]}), a, b);
    } else if (si > 0 && sj <= 0) {
      res += projection_len(*l.intersection({poly[i], poly[j]}), a, b);
    }
  }
  return abs(res);
}

void solve() {
  int n, q;
  cin >> n >> q;
  Polygon<double> v(n);
  for (auto &[x, y] : v) cin >> x >> y;
  if (!is_clockwise(v)) reverse(begin(v), end(v));
  while (q--) {
    Point<double> a, b;
    cin >> a >> b;
    cout << fixed << setprecision(10) << polygon_cut_length(v, a, b) << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
