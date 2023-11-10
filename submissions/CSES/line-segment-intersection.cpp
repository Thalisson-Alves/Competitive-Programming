#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

constexpr double EPS = 1e-6;
template <typename T> bool eq(const T a, const T b) {
  if constexpr (is_floating_point_v<T>) return fabs(a - b) <= EPS;
  else return a == b;
}

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
  inline bool operator<(const Point &p) const { return eq(x, p.x) ? y < p.y : x < p.x; }
  inline bool operator>(const Point &p) const { return eq(x, p.x) ? y > p.y : x > p.x; }
  inline bool operator<=(const Point &p) const { return *this == p or *this < p; }
  inline bool operator>=(const Point &p) const { return *this == p or *this > p; }

  friend ostream& operator<<(ostream &os, const Point &p) { return os << p.x << ' ' << p.y; }
  friend istream& operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }

  inline T dot(const Point &p) const { return x * p.x + y * p.y; }
  inline T cross(const Point &p) const { return x * p.y - y * p.x; }
  inline T cross(const Point &a, const Point &b) const { return (a - *this).cross(b - *this); }
  inline T dist2() const { return x * x + y * y; }
  inline double dist() const { return hypot(x, y); }
  inline double angle() const { return atan2(y, x); }
};

template<typename T=double> struct Segment {
  Point<T> a, b;

  Segment() : a(), b() {}
  Segment(Point<T> a_, Point<T> b_) : a(a_), b(b_) {}

  inline bool operator==(const Segment &l) const { return a == l.a and b == l.b; }

  inline bool intersects(const Segment &l) const {
    if (eq(a.cross(b, l.a), (T)0) and eq(a.cross(b, l.b), (T)0)) {
      return min(a, b) <= max(l.a, l.b) and min(l.a, l.b) <= max(a, b);
    }
    return (a.cross(b, l.a) * a.cross(b, l.b) <= 0) and (l.a.cross(l.b, a) * l.a.cross(l.b, b) <= 0);
  }

  inline bool intersects(const Point<T> &p) const {
    return eq(a.cross(b, p), 0) and min(a, b) <= p and p <= max(a, b);
  }

  inline Point<T> intersection(const Segment &l) const {
    assert(intersects(l));
    if (eq(a.cross(b, l.a), 0) and eq(a.cross(b, l.b), 0)) {
      return min(a, b) <= max(l.a, l.b) ? max(a, l.a) : min(a, l.a);
    }
    return a + (b - a) * (l.a.cross(l.b, l.a) / l.a.cross(l.b, a - b));
  }

  inline T dist2(const Point<T> &p) const {
    if (eq(a.cross(b, p), 0)) return min((p - a).dist2(), (p - b).dist2());
    return pow(a.cross(b, p), 2) / (a - b).dist2();
  }

  inline double dist(const Point<T> &p) const { return sqrt(dist2(p)); }

  friend ostream& operator<<(ostream &os, const Segment &l) { return os << l.a << ' ' << l.b; }
  friend istream& operator>>(istream &is, Segment &l) { return is >> l.a >> l.b; }
};

void solve() {
  Segment a, b;
  cin >> a >> b;
  cout << (a.intersects(b) ? "YES" : "NO") << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
