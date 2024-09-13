template <typename T> struct Circle {
  Point<T> c; T r;
  Circle() : c(), r(0) {}
  Circle(Point<T> c_, T r_) : c(c_), r(r_) {}
  template <typename U> bool contains(const Point<U> &p) { return c.dist(p) <= r; }
  pair<Point<T>, Point<T>> tangent_points(const Point<T> &p) {
    long double d1 = (p - c).norm(), theta = asin(r / d1);
    assert(d1 >= r);
    auto p1 = (c-p).rotated(theta) * sqrt(d1*d1 - r*r) / d1 + p;
    auto p2 = (c-p).rotated(-theta) * sqrt(d1*d1 - r*r) / d1 + p;
    return {p1, p2};
  }
  long double area() const { return acos(-1)*r*r; }
  long double intersection_area(const Circle &o) const {
    auto d = c.dist(o.c);
    if (d > r + o.r) return 0;
    if (d <= (r-o.r) and r >= o.r) return o.area();
    if (d <= (o.r-r) and o.r >= r) return area();
    auto alpha = acos((r*r+d*d-o.r*o.r) / (2*r*d)) * 2;
    auto beta = acos((o.r*o.r+d*d-r*r) / (2*o.r*d)) * 2;
    auto a1 = .5*beta*o.r*o.r-.5*o.r*o.r*sin(beta);
    auto a2 = .5*alpha*r*r-.5*r*r*sin(alpha);
    return a1+a2;
  }
  long double intersection_area(const Polygon<T> &ps) const {
    auto arg = [&](const Point<T> &p, const Point<T> &q) {
      return atan2(p.cross(q), p.dot(q));
    };
    auto tri = [&](const Point<T> &p, const Point<T> &q) {
      auto r2 = r*r/2;
      auto d = q - p;
      auto a = d.dot(p)/d.dist2(), b = (p.dist2()-r*r)/d.dist2();
      auto det = a*a-b;
      if (det <= 0) return arg(p, q) * r2;
      auto s = max(.0, -a-sqrt(det)), t = min(1., -a+sqrt(det));
      if (t < 0 or 1 <= s) return arg(p, q) * r2;
      auto u = p + d * s, v = p + d * t;
      return arg(p, u) * r2 + u.cross(v) / 2 + arg(v, q) * r2;
    };
    double res = 0;
    for (int i = 0; i < (int)size(ps); i++)
      res += tri(ps[i] - c, ps[(i + 1) % size(ps)] - c);
    return res;
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

template <typename T> Circle<long double> minimum_enclosing_circle(vector<Point<T>> &p) {
  random_shuffle(begin(p), end(p));
  Circle<long double> res(p[0], 0);
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
