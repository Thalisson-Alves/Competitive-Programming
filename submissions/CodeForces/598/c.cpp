#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

template<typename T=double> struct Point {
  T x, y;
  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}
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
bool angle_less(const Point<T> &a1, const Point<T> &b1, const Point<T> &a2, const Point<T> &b2) {
  Point<T> p1(a1.dot(b1), abs(a1.cross(b1)));
  Point<T> p2(a2.dot(b2), abs(a2.cross(b2)));
  return p1.cross(p2) <= 0;
}

void solve() {
  int n; cin >> n;
  vector<Point<ll>> pts(n);
  for (auto &[x, y]: pts) cin >> x >> y;
  vector<int> o(n);
  iota(begin(o), end(o), 0);
  static const int quad[][2] = {{0,3},{1,2}};
  sort(begin(o), end(o), [&](int i, int j) {
    auto qi = quad[pts[i].x<0][pts[i].y<0];
    auto qj = quad[pts[j].x<0][pts[j].y<0];
    if (qi!=qj) return qi<qj;
    return pts[i].cross(pts[j])>0;
  });
  int r1 = o[0], r2 = o[n-1];
  for (int i = 1; i < n; i++) {
    if (angle_less(pts[r1],pts[r2],pts[o[i]],pts[o[i-1]]))
      r1=o[i],r2=o[i-1];
  }
  cout << r1+1 << ' ' << r2+1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
