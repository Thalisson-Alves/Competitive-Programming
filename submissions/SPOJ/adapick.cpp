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
  if constexpr (is_floating_point<T>()) return fabs(a - b) <= EPS;
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

template <typename T> bool polar_less(const Point<T> &a, const Point<T> &b) {
  auto top = [](const Point<T> &p) { return p.y < 0 or (!p.y and p.x < 0); };
  auto ta = top(a);
  auto tb = top(b);
  if (ta != tb) return ta;
  return a.cross(b) > 0;
}

void solve() {
  int n;
  cin >> n;
  vector<Point<ll>> pts(n<<1);
  for (auto &p : pts) cin >> p;
  vector<pair<Point<ll>, bool>> es;
  int cnt = 0, res = 0;
  for (int i = 0; i < n; i++) {
    auto &a = pts[i<<1];
    auto &b = pts[i<<1|1];
    if (polar_less(b, a)) swap(a,b);
    if (min(a.y,b.y) <= 0 and max(a.y,b.y) > 0 and a.to(b).cross(a.to({})) < 0) {
      ++cnt;
      ++res;
      es.emplace_back(a, 1);
      es.emplace_back(b, 0);
    } else {
      es.emplace_back(a, 0);
      es.emplace_back(b, 1);
    }
  }
  sort(begin(es), end(es), [&](const auto &a, const auto& b) {
    auto top = [](const auto &p) { return p.y < 0 or (!p.y and p.x < 0); };
    auto ta = top(a.first);
    auto tb = top(b.first);
    if (ta != tb) return ta;
    if (auto c = a.first.cross(b.first)) return c > 0;
    return a.second < b.second;
  });
  for (auto [_, closing] : es) {
    if (closing) --cnt;
    else ++cnt;
    res = max(res, cnt);
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
