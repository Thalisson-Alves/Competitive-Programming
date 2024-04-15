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
    return (o < 0 or o == 0);
  else
    return o < 0;
}

template<const bool include_collinear=false, typename T> bool ccw(const Point<T> &p, const Point<T> &a, const Point<T> &b) {
  auto o = orientation(p, a, b);
  if constexpr (include_collinear)
    return (o > 0 or o == 0);
  else
    return o > 0;
}

/* Check if point p is inside triangle v1, v2, v3 */
template <typename T> bool is_inside_triangle(const Point<T> &p, const Point<T> &v1, const Point<T> &v2, const Point<T> &v3) {
  auto o1 = orientation(p, v1, v2);
  auto o2 = orientation(p, v2, v3);
  auto o3 = orientation(p, v3, v1);

  bool neg = (o1 < 0) or (o2 < 0) or (o3 < 0);
  bool pos = (o1 > 0) or (o2 > 0) or (o3 > 0);
  return !neg or !pos;
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
