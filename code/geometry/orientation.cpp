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
