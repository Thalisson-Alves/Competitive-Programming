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
    return eq(a.cross(b, p), (T)0) and min(a, b) <= p and p <= max(a, b);
  }

  inline Point<T> intersection(const Segment &l) const {
    assert(intersects(l));
    if (eq(a.cross(b, l.a), (T)0) and eq(a.cross(b, l.b), (T)0)) {
      return min(a, b) <= max(l.a, l.b) ? max(a, l.a) : min(a, l.a);
    }
    return a + (b - a) * (l.a.cross(l.b, l.a) / l.a.cross(l.b, a - b));
  }

  inline Point<T> closest(const Point<T> & p) const {
    if ((p - a).dot(b - a) < EPS) return a;
    if ((p - b).dot(a - b) < EPS) return b;

    return a + (b - a) * ((p - a).dot(b - a) / (b - a).dist2());
  }

  inline double dist2(const Point<T> &p) const { return (p-closest(p)).dist2(); }
  inline double dist(const Point<T> &p) const { return sqrt(dist2(p)); }

  bool operator<(const Segment &l) const {
    if (a.x < l.a.x) return a.to(b).cross(a.to(l.a)) < 0;
    else return l.a.to(l.b).cross(l.a.to(a)) > 0;
  }

  friend ostream& operator<<(ostream &os, const Segment &l) { return os << l.a << ' ' << l.b; }
  friend istream& operator>>(istream &is, Segment &l) { return is >> l.a >> l.b; }
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
