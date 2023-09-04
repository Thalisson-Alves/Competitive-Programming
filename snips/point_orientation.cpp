template<typename T>
int orientation(const Point<T> &a, const Point<T> &b, const Point<T> &c)
{
  auto x = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
  bool is_zero = false;
  if constexpr (is_floating_point<T>())
    is_zero = feq(x, 0.0);
  else
    is_zero = x == 0;

  if (is_zero) return 0;
  return (x < 0 ? -1 : 1);
}

template<typename T>
bool collinear(const Point<T> &a, const Point<T> &b, const Point<T> &c)
{
  return feq(orientation(a, b, c), 0.0);
}

template<const bool include_collinear=false, typename T>
bool cw(const Point<T> &a, const Point<T> &b, const Point<T> &c)
{
  auto o = orientation(a, b, c);
  if constexpr (include_collinear)
    return (o < 0 or o == 0);
  else
    return o < 0;
}

template<const bool include_collinear=false, typename T>
bool ccw(const Point<T> &a, const Point<T> &b, const Point<T> &c)
{
  auto o = orientation(a, b, c);
  if constexpr (include_collinear)
    return (o > 0 or o == 0);
  else
    return o > 0;
}
