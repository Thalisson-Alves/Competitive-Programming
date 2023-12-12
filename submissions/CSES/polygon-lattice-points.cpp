#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

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
  inline double norm() const { return sqrt(dot(*this)); }
  inline Point rot90() const { return Point(-y, x); }
  inline Point to(const Point &p) const { return p - *this; }
};

template<typename T> int orientation(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
  auto x = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
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

template<const bool include_collinear=false, typename T> bool cw(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
  auto o = orientation(a, b, c);
  if constexpr (include_collinear)
    return (o < 0 or o == 0);
  else
    return o < 0;
}

template<const bool include_collinear=false, typename T> bool ccw(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
  auto o = orientation(a, b, c);
  if constexpr (include_collinear)
    return (o > 0 or o == 0);
  else
    return o > 0;
}

template<typename T=double> struct Segment {
  Point<T> p, q;

  Segment() : p(), q() {}
  Segment(Point<T> a_, Point<T> b_) : p(a_), q(b_) {}

  inline bool operator==(const Segment &l) const { return p == l.p and q == l.q; }

  inline bool intersects(const Segment &l) const {
    if (eq(p.cross(q, l.p), (T)0) and eq(p.cross(q, l.q), (T)0)) {
      return min(p, q) <= max(l.p, l.q) and min(l.p, l.q) <= max(p, q);
    }
    return (p.cross(q, l.p) * p.cross(q, l.q) <= 0) and (l.p.cross(l.q, p) * l.p.cross(l.q, q) <= 0);
  }

  inline bool intersects(const Point<T> &r) const {
    return eq(p.cross(q, r), (T)0) and min(p, q) <= r and r <= max(p, q);
  }

  inline Point<T> intersection(const Segment &l) const {
    assert(intersects(l));
    if (eq(p.cross(q, l.p), (T)0) and eq(p.cross(q, l.q), (T)0)) {
      return min(p, q) <= max(l.p, l.q) ? max(p, l.p) : min(p, l.p);
    }
    return p + (q - p) * (l.p.cross(l.q, l.p) / l.p.cross(l.q, p - q));
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

template <typename T> void sort_segments(vector<Segment<T>> &segments) {
  sort(all(segments), [](const auto &a, const auto &b) {
    return a.a.x < b.a.x;
  });

  vector<vector<int>> g(segments.size()+1);
  set<pair<Segment<T>, int>> st;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> events;

  for (int i = 0; i < (int)segments.size(); i++) {
    while (not events.empty() and events.top().first < segments[i].a.x) {
      auto [x, y] = events.top();
      events.pop();
      st.erase({segments[y], y});
    }

    auto it = st.insert({segments[i], i}).first;
    g[it == st.begin() ? segments.size() : prev(it)->second].push_back(i);
    events.push({segments[i].b.x, i});
  }

  stack<int> dfs;
  dfs.push((int)segments.size());
  vector<Segment<T>> res;

  while (not dfs.empty()) {
    auto u = dfs.top();
    dfs.pop();

    if (u != (int)segments.size()) res.push_back(segments[u]);
    for (auto v : g[u]) dfs.push(v);
  }

  swap(segments, res);
}

template<typename T>
T polygon_area(const vector<Point<T>> &pts) {
  T res = 0;
  for (int i = 2; i < (int)pts.size(); i++) {
    res += pts[0].cross(pts[i-1], pts[i]);
  }
  return abs(res) / 2;
}

template<typename T>
ll boundary_points(const vector<Point<T>> &pts) {
  ll res = 0;
  for (int i = 0; i < (int)pts.size() - 1; i++) {
    res += gcd(abs(pts[i].x - pts[i+1].x), abs(pts[i].y - pts[i+1].y));
  }
  res += gcd(abs(pts.back().x - pts[0].x), abs(pts.back().y - pts[0].y));
  return res;
}

template<typename T>
pair<ll, ll> lattice_points(const vector<Point<T>> &pts) {
  ll b = boundary_points(pts);
  ll a = polygon_area(pts);
  return {a - b / 2 + 1, b};
}

void solve() {
  int n;
  cin >> n;

  vector<Point<ll>> pts(n);
  for (auto &x : pts) cin >> x;

  auto [a, b] = lattice_points(pts);
  cout << a << ' ' << b << '\n';
}

int32_t main()
{
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
