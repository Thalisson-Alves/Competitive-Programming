#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

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

template<typename T> int orientation(const Point<T> &a, const Point<T> &b, const Point<T> &c)
{
  auto x = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
  auto is_zero = [](auto x) -> bool {
    if constexpr (is_floating_point<T>())
      return feq(x, 0.0);
    else
      return x == 0;
  };
  if (is_zero(x)) return 0;
  return (x < 0 ? -1 : 1);
}

template<typename T>
bool collinear(const Point<T> &a, const Point<T> &b, const Point<T> &c)
{
  return feq(orientation(a, b, c), 0.0);
}

void solve()
{
  vector<Point<ll>> a(3);
  for (auto &x : a) cin >> x;
  auto o = orientation(a[0], a[1], a[2]);
  if (o == 1)
    cout << "LEFT\n";
  else if (o == -1)
    cout << "RIGHT\n";
  else
    cout << "TOUCH\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}

