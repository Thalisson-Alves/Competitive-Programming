template<typename T> using Polygon = vector<Point<T>>;

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
template <typename T> bool inside_convex(const Polygon<T> &poly, const Point<T> &p) {
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

template<typename T> int inside_simple(const Polygon<T> &poly, const Point<T> &p) {
  int w = 0;
  for (int i = 0; i < (int)size(poly); i++) {
    if (p == poly[i]) return 0;
    int j = (i+1)%size(poly);
    if (poly[i].y == p.y && poly[j].y == p.y) {
      if (min(poly[i].x, poly[j].x) <= p.x && p.x <= max(poly[i].x, poly[j].x))
        return 0;
    } else {
      bool ibelow = poly[i].y < p.y;
      bool jbelow = poly[j].y < p.y;
      if (ibelow != jbelow) {
        auto o = orientation(p, poly[i], poly[j]);
        if (o == 0) return 0;
        if (ibelow == (o > 0)) w += (ibelow ? +1 : -1);
      }
    }
  }
  return (w ? 1 : -1);
}
template<typename T> double sarea(const Polygon<T> &poly) {
  int n = (int)size(poly);
  double total = 0;
  for (int i = 0; i < n; i++) {
    total += poly[i].x * poly[(i+1)%n].y;
    total -= poly[i].y * poly[(i+1)%n].x;
  }
  return total/2;
}
template <typename T> double area(const Polygon<T> &poly) { return abs(sarea(poly)); }
template <typename T> bool is_clockwise(const Polygon<T> &poly) { return sarea(poly) < 0; }
/* Length of the common part of a polygon (poly) and a line (a-b)
 *
 * Time complexity: O(n)
 */
template<typename T> T polygon_cut_length(const Polygon<T> &poly, const Point<T> &a, const Point<T> &b) {
  Line<T> l(a, b);
  T res = 0;
  for (int i = 0; i < (int)size(poly); i++) {
    int j = (i+1)%(int)size(poly);
    int si = orientation(poly[i], a, b);
    int sj = orientation(poly[j], a, b);
    if (eq(si, 0) and eq(sj, 0)) {
      if ((b-a).dot(poly[j]-poly[i]) > 0) {
        res += projection_len(poly[j], a, b);
        res -= projection_len(poly[i], a, b);
      }
    } else if (si <= 0 && sj > 0) {
      res -= projection_len(*l.intersection({poly[i], poly[j]}), a, b);
    } else if (si > 0 && sj <= 0) {
      res += projection_len(*l.intersection({poly[i], poly[j]}), a, b);
    }
  }
  return abs(res);
}
