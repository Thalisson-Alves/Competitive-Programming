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
  if constexpr (is_floating_point<T>()) is_zero = eq(x, 0.0);
  else is_zero = x == 0;
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
