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
template<typename T=long double> struct Point {
  T x, y;
  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}
  template <typename U> operator Point<U>() const { return {(U)x, (U)y}; }
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
  constexpr auto top = [](const Point<T> &p) { return p.y < 0 or (!p.y and p.x < 0); };
  auto ta = top(a);
  auto tb = top(b);
  if (ta != tb) return ta;
  return a.cross(b) > 0;
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

template <typename T> using Halfplane = pair<Point<T>, Point<T>>;
template <typename T> bool out(const Halfplane<T> &h, const Point<T> &p) {
  return h.second.cross(p - h.first) < 0;
}
template <typename T> Point<long double> inter(const Halfplane<T> &s, const Halfplane<T> &t) {
  long double alpha = (t.first - s.first).cross(t.second) / (long double)s.second.cross(t.second);
  return (Point<long double>)s.first + ((Point<long double>)s.second * alpha);
}
template <typename T> vector<Point<long double>> half_plane_intersection(vector<pair<Point<T>, Point<T>>> h) {
  constexpr T inf = 1e8;
  h.insert(end(h), {
    {{inf, inf}, {-inf, inf}},
    {{-inf, inf}, {-inf, -inf}},
    {{-inf, -inf}, {inf, -inf}},
    {{inf, -inf}, {inf, inf}},
  });
  for (auto &[a, b] : h) b -= a;
  if constexpr (is_integral_v<T>) sort(begin(h), end(h), [](const auto &a, const auto &b) { return polar_less(a.second, b.second); });
  else sort(begin(h), end(h), [](const auto &a, const auto &b) { return a.second.angle() < b.second.angle(); });
  deque<Halfplane<T>> dq;
  for (int i = 0; i < (int)size(h); i++) {
    while (size(dq) > 1 and out({h[i].first, h[i].second}, inter(rbegin(dq)[0], rbegin(dq)[1]))) dq.pop_back();
    while (size(dq) > 1 and out({h[i].first, h[i].second}, inter(dq[0], dq[1]))) dq.pop_front();
    if (size(dq) and eq(h[i].second.cross(rbegin(dq)[0].second), (T)0)) {
      if (h[i].second.dot(rbegin(dq)[0].second) < 0) return {};
      if (out(h[i], rbegin(dq)[0].first)) dq.pop_back();
      else continue;
    }
    dq.push_back(h[i]);
  }
  while (size(dq) > 2 and out({dq[0].first, dq[0].second}, inter(rbegin(dq)[0], rbegin(dq)[1]))) dq.pop_back();
  while (size(dq) > 2 and out({rbegin(dq)->first, rbegin(dq)->second}, inter(dq[0], dq[1]))) dq.pop_front();
  if (size(dq) < 3) return {};
  vector<Point<long double>> res(size(dq));
  for (int i = 0; i < (int)size(dq)-1; i++) res[i] = inter(dq[i], dq[i+1]);
  res.back() = inter(*rbegin(dq), dq[0]);
  return res;
}

void solve() {
  int n; long double d;
  cin >> n >> d;
  vector<Halfplane<ll>> h(n);
  for (auto &[s, t] : h) {
    cin >> s >> t;
    if (out<ll>({s, t-s}, {0,0})) swap(s, t);
  }
  auto f = [&](int k) {
    auto hull = half_plane_intersection(vector<Halfplane<ll>>(begin(h), begin(h)+k));
    for (auto p : hull) {
      if (p.dist() >= d) return true;
    }
    return empty(hull);
  };
  int l = 3, r = n;
  while (l <= r) {
    auto mid = midpoint(l, r);
    if (f(mid)) l = mid + 1;
    else r = mid - 1;
  }
  if (l > n) cout << "*\n";
  else cout << l << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
