constexpr double EPS = 1e-9;
template <typename T> bool eq(const T a, const T b) {
  if constexpr (is_floating_point_v<T>) return fabs(a - b) <= EPS;
  else return a == b;
}

const double PI = acos(-1);
double to_rad(double deg) { return deg * PI / 180; }
double to_deg(double rad) { return rad * 180 / PI; }

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
    return o <= 0;
  else
    return o < 0;
}

template<const bool include_collinear=false, typename T> bool ccw(const Point<T> &p, const Point<T> &a, const Point<T> &b) {
  auto o = orientation(p, a, b);
  if constexpr (include_collinear)
    return o >= 0;
  else
    return o > 0;
}

/* Check if point p is inside triangle v1, v2, v3 */
template <typename Pt> bool is_inside_triangle(const Pt &p, const Pt &v1, const Pt &v2, const Pt &v3) {
  auto o1 = orientation(p, v1, v2);
  auto o2 = orientation(p, v2, v3);
  auto o3 = orientation(p, v3, v1);

  bool neg = (o1 < 0) or (o2 < 0) or (o3 < 0);
  bool pos = (o1 > 0) or (o2 > 0) or (o3 > 0);
  return !neg or !pos;
}

/* Check if point p is inside a convex polygon
 *
 * Points i and i+1 must represent a segment of the polygon
 *
 * Time complexity: O(log n)
*/
template <typename Pt> bool is_inside_polygon(const vector<Pt> &poly, const Pt &p) {
  int l = 2, r = (int)poly.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ccw<true>(p, poly[0], poly[mid]))
      l = mid + 1;
    else
      r = mid - 1;
  }

  return is_inside_triangle(p, poly[0], poly[r-1], poly[r]);
}

template <typename T>
T rect_overlapping_area(pair<T, T> l1, pair<T, T> r1, pair<T, T> l2, pair<T, T> r2) {
  auto a1 = abs(l1.first - r1.first) * abs(l1.second - r1.second);
  auto a2 = abs(l2.first - r2.first) * abs(l2.second - r2.second);
  auto dx = min(r1.first, r2.first) - max(l1.first, l2.first);
  auto dy = min(r1.second, r2.second) - max(l1.second, l2.second);
  T ai = (dx > 0 and dy > 0 ? dx * dy : 0);
  return a1 + a2 - ai;
}

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
  sort(segments.begin(), segments.end(), [](const auto &a, const auto &b) {
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
