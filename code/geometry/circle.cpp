template <typename T> struct Circle {
  Point<T> c; T r;
  Circle() : c(), r(0) {}
  Circle(Point<T> c_, T r_) : c(c_), r(r_) {}
  template <typename U> bool contains(const Point<U> &p) { return c.dist(p) <= r; }
  pair<Point<T>, Point<T>> tangent_points(const Point<T> &p) {
    double d1 = (p - c).norm(), theta = asin(r / d1);
    assert(d1 >= r);
    auto p1 = (c-p).rotated(theta) * sqrt(d1*d1 - r*r) / d1 + p;
    auto p2 = (c-p).rotated(-theta) * sqrt(d1*d1 - r*r) / d1 + p;
    return {p1, p2};
  }
  friend ostream& operator<<(ostream &os, const Circle &cr) { return os << cr.c << ' ' << cr.r; }
  friend istream& operator>>(istream &is, Circle &cr) { return is >> cr.c >> cr.r; }
};

template <typename T> Circle<T> circumcircle(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
  Point<T> u = {(b-a).y, (a-b).x};
  Point<T> v = {(c-a).y, (a-c).x};
  Point<T> n = (c-b)/2.;
  auto t = u.cross(n) / v.cross(u);
  Point<T> center = ((a+c)/2.)+v*t;
  return {center, center.dist(a)};
}

template <typename T> Circle<double> minimum_enclosing_circle(vector<Point<T>> &p) {
  random_shuffle(begin(p), end(p));
  Circle<double> res(p[0], 0);
  for (int i = 0; i < (int)size(p); i++) {
    if (res.contains(p[i])) continue;
    res = {p[i], 0};
    for (int j = 0; j < i; j++) {
      if (res.contains(p[j])) continue;
      res = {(p[j]+p[i])/2., p[j].dist(p[i])/2.};
      for (int k = 0; k < j; k++) {
        if (res.contains(p[k])) continue;
        res = circumcircle(p[j], p[i], p[k]);
      }
    }
  }
  return res;
}
