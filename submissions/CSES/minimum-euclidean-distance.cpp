#include <bits/stdc++.h>
#include <limits>
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
template<typename T=long double> struct Point {
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
  T dist2(const Point &p) const { return to(p).dist2(); }
  long double dist() const { return hypot(x, y); }
  long double dist(const Point &p) const { return to(p).dist(); }
  long double angle() const { return atan2(y, x); }
  long double angle(const Point &p) const { return atan2(cross(p), dot(p)); }
  long double norm() const { return sqrt(dot(*this)); }
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

template <typename T> T min_dist2(vector<Point<T>> ps) {
  sort(begin(ps), end(ps));
  T res = numeric_limits<T>::max();
  set<Point<T>> st = {{ps[0].y, ps[0].x}};
  for (int i = 1, j = 0; i < (int)size(ps); i++) {
    T dd = (T)ceil(sqrt(res));
    for (; j < i and ps[j].x < ps[i].x-dd; st.erase({ps[j].y, ps[j].x}), ++j);
    auto l = st.lower_bound({ps[i].y-dd, 0});
    auto r = st.upper_bound({ps[i].y+dd, 0});
    for (auto it = l; it != r; it++)
      res = min(res, ps[i].dist2({it->y, it->x}));
    st.insert({ps[i].y, ps[i].x});
  }
  return res;
}
template <typename T> long double min_dist(const vector<Point<T>> &ps) { return sqrtl(min_dist2(ps)); }

void solve() {
  int n; cin >> n;
  vector<Point<ll>> ps(n);
  for (auto &[x, y] : ps) cin >> x >> y;
  cout << min_dist2(ps) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
