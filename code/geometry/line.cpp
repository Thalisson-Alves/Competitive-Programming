template <typename T = long double> struct Line {
  T a, b, c; // ax + by = c
  Line() : a(0), b(0), c(0) {}
  Line(T a_, T b_, T c_) : a(a_), b(b_), c(c_) {}
  Line(const Point<T> &p, const Point<T> &q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = p.cross(q);
  }
  double eval(T x) const { return (c-a*x)/b; }
  double dist(const Point<T> &p) const { return abs(a*p.x+b*p.y+c)/(sqrt(a*a+b*b)); }
  bool parallel(const Line &l) const { return eq(a * l.b, b * l.a); }
  optional<Point<T>> intersection(const Line &l) const {
    if (parallel(l)) return {};
    auto det = a * l.b - b * l.a;
    return Point<T>((b * l.c - c * l.b) / det, (c * l.a - a * l.c) / det);
  }
  bool operator==(const Line &l) const { return eq(a, l.a) and eq(b, l.b) and eq(c, l.c); }
};
