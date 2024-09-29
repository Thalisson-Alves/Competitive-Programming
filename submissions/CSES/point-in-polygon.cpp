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

// ang(a1,b1) <= ang(a2,b2)
template <typename T>
bool angle_less(const Point<T> &a1, const Point<T> &b1, const Point<T> &a2, const Point<T> &b2) {
  Point<T> p1(a1.dot(b1), abs(a1.cross(b1)));
  Point<T> p2(a2.dot(b2), abs(a2.cross(b2)));
  return p1.cross(p2) <= 0;
}

template <typename T>
T projection_len(const Point<T> &p, const Point<T> &a, const Point<T> &b) {
  return (p-a).dot(b-a) / (b-a).norm();
}

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

void solve() {
  int n, q;
  cin >> n >> q;
  Polygon<ll> ps(n);
  for (auto &[x, y] : ps) cin >> x >> y;
  while (q--) {
    Point<ll> p;
    cin >> p;
    auto res = inside_simple(ps, p);
    cout << (res==-1?"OUTSIDE":(res?"INSIDE":"BOUNDARY")) << '\n';
  }
}

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
