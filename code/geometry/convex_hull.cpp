/* Convex hull
 * - If `ic` is true, collinear points are included
 *
 * Time complexity: O(n log n)
*/
template<const bool ic=false, typename T> Polygon<T> convex_hull(Polygon<T> pts) {
  if (pts.size() == 1) return pts;
  sort(pts.begin(), pts.end());
  auto p1 = pts[0], p2 = pts.back();
  vector<Point<T>> up, down;
  up.push_back(p1);
  down.push_back(p1);
  for (size_t i = 1; i < pts.size(); i++) {
    if (i == pts.size() - 1 or cw<ic>(p1, pts[i], p2)) {
      while (up.size() >= 2 and !cw<ic>(up[up.size()-2], up[up.size()-1], pts[i])) up.pop_back();
      up.push_back(pts[i]);
    }
    if (i == pts.size() - 1 or ccw<ic>(p1, pts[i], p2)) {
      while (down.size() >= 2 and !ccw<ic>(down[down.size()-2], down[down.size()-1], pts[i])) down.pop_back();
      down.push_back(pts[i]);
    }
  }
  if constexpr (ic) {
    if (up.size() == pts.size()) {
      reverse(pts.begin(), pts.end());
      return pts;
    }
  }
  up.insert(up.end(), down.rbegin() + 1, down.rend() - 1);
  return up;
}
