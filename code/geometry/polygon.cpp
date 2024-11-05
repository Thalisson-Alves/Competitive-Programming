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
template<typename T> T sarea2(const Polygon<T> &poly) {
  int n = (int)size(poly);
  T total = 0;
  for (int i = 0; i < n; i++) {
    total += poly[i].x * poly[(i+1)%n].y;
    total -= poly[i].y * poly[(i+1)%n].x;
  }
  return total;
}
template<typename T> double sarea(const Polygon<T> &poly) { return sarea2(poly) / 2.0; }
template <typename T> double area(const Polygon<T> &poly) { return abs(sarea(poly)); }
template <typename T> bool is_clockwise(const Polygon<T> &poly) { return sarea2(poly) < 0; }
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

template <typename T> double polygon_union_area(const vector<Polygon<T>> &poly) {
  using P = Point<T>;
  constexpr auto sgn = [](auto x) { return (x > 0) - (x < 0); };
  auto rat = [&](P a, P b) { return sgn(b.x) ? 1.*a.x/b.x : 1.*a.y/b.y; };
  auto side_of = [&](P s, P e, P p) { return sgn(s.cross(e, p)); };
	double ret = 0;
	for (int i = 0; i < (int)size(poly); i++) for (int v = 0; v < (int)size(poly[i]); v++) {
		P A = poly[i][v], B = poly[i][(v + 1) % (int)size(poly[i])];
		vector<pair<double, int>> segs = {{0, 0}, {1, 0}};
		for (int j = 0; j < (int)size(poly); j++) if (i != j) {
			for (int u = 0; u < (int)size(poly[j]); u++) {
				P C = poly[j][u], D = poly[j][(u + 1) % (int)size(poly[j])];
				int sc = side_of(A, B, C), sd = side_of(A, B, D);
				if (sc != sd) {
					double sa = C.cross(D, A), sb = C.cross(D, B);
					if (min(sc, sd) < 0) segs.emplace_back(sa / (sa - sb), sgn(sc - sd));
				} else if (!sc && !sd && j<i && sgn((B-A).dot(D-C))>0){
					segs.emplace_back(rat(C - A, B - A), 1);
					segs.emplace_back(rat(D - A, B - A), -1);
				}
			}
		}
		sort(begin(segs), end(segs));
		for (auto& s : segs) s.first = min(max(s.first, 0.0), 1.0);
		double sum = 0;
		int cnt = segs[0].second;
		for (int j = 1; j < (int)size(segs); j++) {
			if (!cnt) sum += segs[j].first - segs[j - 1].first;
			cnt += segs[j].second;
		}
		ret += A.cross(B) * sum;
	}
	return ret / 2;
}
