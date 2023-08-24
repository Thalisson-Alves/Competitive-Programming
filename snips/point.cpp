template<typename T>
struct Point
{
  T x, y;

  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}

  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  Point operator+(const T &k) const { return Point(x + k, y + k); }
  Point operator-(const T &k) const { return Point(x - k, y - k); }
  Point operator*(const T &k) const { return Point(x * k, y * k); }
  Point operator/(const T &k) const { return Point(x / k, y / k); }

  Point& operator+=(const Point &p) { x += p.x, y += p.y; return *this; }
  Point& operator-=(const Point &p) { x -= p.x, y -= p.y; return *this; }
  Point& operator+=(const T &k) { x += k, y += k; return *this; }
  Point& operator-=(const T &k) { x -= k, y -= k; return *this; }
  Point& operator*=(const T &k) { x *= k, y *= k; return *this; }
  Point& operator/=(const T &k) { x /= k, y /= k; return *this; }

  bool operator==(const Point &p) const { return x == p.x && y == p.y; }
  bool operator!=(const Point &p) const { return x != p.x || y != p.y; }
  bool operator<(const Point &p) const { return x < p.x || (x == p.x && y < p.y); }
  bool operator>(const Point &p) const { return x > p.x || (x == p.x && y > p.y); }
  bool operator<=(const Point &p) const { return x <= p.x && y <= p.y; }
  bool operator>=(const Point &p) const { return x >= p.x && y >= p.y; }

  friend ostream& operator<<(ostream &os, const Point &p) { return os << '(' << p.x << ", " << p.y << ')'; }
  friend istream& operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }

  T dot(const Point &p) const { return x * p.x + y * p.y; }
  T cross(const Point &p) const { return x * p.y - y * p.x; }
  T cross(const Point &a, const Point &b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  double dist() const { return hypot(x, y); }
  double angle() const { return atan2(y, x); }
};
