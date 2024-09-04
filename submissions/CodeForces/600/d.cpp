#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

#define double long double

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

template <typename T> struct Circle {
  Point<T> c; T r;
  Circle() : c(), r(0) {}
  Circle(Point<T> c_, T r_) : c(c_), r(r_) {}
  template <typename U> bool contains(const Point<U> &p) { return c.dist(p) <= r; }
  pair<Point<T>, Point<T>> tangent_points(const Point<T> &p) {
    double d1 = (p - c).norm(), theta = asin(r / d1);
    assert(d1 >= r);
    auto p1 = (c-p).rotated(theta) * sqrt(d1*d1 - r*r) / d1 + p;
    auto p2 = (c-p).rotated(-theta) * sqrt(d1*d1 - r*r) / d1 + p;
    return {p1, p2};
  }
  double area() const { return acos(-1)*r*r; }
  double area_intersection(const Circle &o) const {
    auto d = c.dist(o.c);
    if (d > r + o.r) return 0;
    if (d <= (r-o.r) and r >= o.r) return o.area();
    if (d <= (o.r-r) and o.r >= r) return area();
    auto alpha = acos((r*r+d*d-o.r*o.r) / (2*r*d)) * 2;
    auto beta = acos((o.r*o.r+d*d-r*r) / (2*o.r*d)) * 2;
    auto a1 = .5*beta*o.r*o.r-.5*o.r*o.r*sin(beta);
    auto a2 = .5*alpha*r*r-.5*r*r*sin(alpha);
    return a1+a2;
  }
  friend ostream& operator<<(ostream &os, const Circle &cr) { return os << cr.c << ' ' << cr.r; }
  friend istream& operator>>(istream &is, Circle &cr) { return is >> cr.c >> cr.r; }
};

template <typename T> Circle<T> circumcircle(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
  Point<T> u = {(b-a).y, (a-b).x};
  Point<T> v = {(c-a).y, (a-c).x};
  Point<T> n = (c-b)/2.;
  auto t = u.cross(n) / v.cross(u);
  Point<T> center = ((a+c)/2.)+v*t;
  return {center, center.dist(a)};
}

template <typename T> Circle<double> minimum_enclosing_circle(vector<Point<T>> &p) {
  random_shuffle(begin(p), end(p));
  Circle<double> res(p[0], 0);
  for (int i = 0; i < (int)size(p); i++) {
    if (res.contains(p[i])) continue;
    res = {p[i], 0};
    for (int j = 0; j < i; j++) {
      if (res.contains(p[j])) continue;
      res = {(p[j]+p[i])/2., p[j].dist(p[i])/2.};
      for (int k = 0; k < j; k++) {
        if (res.contains(p[k])) continue;
        res = circumcircle(p[j], p[i], p[k]);
      }
    }
  }
  return res;
}

void solve() {
  Circle<double> a, b;
  cin >> a >> b;
  cout << fixed << setprecision(10) << a.area_intersection(b) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
