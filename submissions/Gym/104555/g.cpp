#include <bits/stdc++.h>
#include <type_traits>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define NDEBUG
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
  int id;

  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}

  inline Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  inline Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  inline Point operator+(const T &k) const { return Point(x + k, y + k); }
  inline Point operator-(const T &k) const { return Point(x - k, y - k); }
  inline Point operator*(const T &k) const { return Point(x * k, y * k); }
  inline Point operator/(const T &k) const { return Point(x / k, y / k); }

  inline Point& operator+=(const Point &p) { x += p.x, y += p.y; return *this; }
  inline Point& operator-=(const Point &p) { x -= p.x, y -= p.y; return *this; }
  inline Point& operator+=(const T &k) { x += k, y += k; return *this; }
  inline Point& operator-=(const T &k) { x -= k, y -= k; return *this; }
  inline Point& operator*=(const T &k) { x *= k, y *= k; return *this; }
  inline Point& operator/=(const T &k) { x /= k, y /= k; return *this; }

  inline bool operator==(const Point &p) const { return x == p.x && y == p.y; }
  inline bool operator!=(const Point &p) const { return x != p.x || y != p.y; }
  inline bool operator<(const Point &p) const { return x < p.x || (x == p.x && y < p.y); }
  inline bool operator>(const Point &p) const { return x > p.x || (x == p.x && y > p.y); }
  inline bool operator<=(const Point &p) const { return x <= p.x && y <= p.y; }
  inline bool operator>=(const Point &p) const { return x >= p.x && y >= p.y; }

  friend ostream& operator<<(ostream &os, const Point &p) { return os << p.x << ' ' << p.y; }
  friend istream& operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }

  inline T dot(const Point &p) const { return x * p.x + y * p.y; }
  inline T cross(const Point &p) const { return x * p.y - y * p.x; }
  inline T cross(const Point &a, const Point &b) const { return (a - *this).cross(b - *this); }
  inline T dist2() const { return x * x + y * y; }
  inline double dist() const { return hypot(x, y); }
  inline double angle() const { return atan2(y, x); }
};

bool feq(double a, double b)
{
  static double EPS = 1e-6;
  return fabs(a-b) < EPS;
}

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

template<const bool include_collinear=false, typename T>
vector<Point<T>> convex_hull(vector<Point<T>> pts)
{
  if (pts.size() == 1) return pts;
 
  sort(all(pts));
  auto p1 = pts[0], p2 = pts.back();
  vector<Point<T>> up, down;
  up.push_back(p1);
  down.push_back(p1);
  for (size_t i = 1; i < pts.size(); i++)
  {
    if (i == pts.size() - 1 or cw<include_collinear>(p1, pts[i], p2))
    {
      while (up.size() >= 2 and !cw<include_collinear>(up[up.size()-2], up[up.size()-1], pts[i]))
        up.pop_back();
      up.push_back(pts[i]);
    }
    if (i == pts.size() - 1 or ccw<include_collinear>(p1, pts[i], p2))
    {
      while (down.size() >= 2 and !ccw<include_collinear>(down[down.size()-2], down[down.size()-1], pts[i]))
        down.pop_back();
      down.push_back(pts[i]);
    }
  }
 
  if constexpr (include_collinear)
  {
    if (up.size() == pts.size())
    {
      reverse(all(pts));
      return pts;
    }
  }
 
  up.insert(up.end(), down.rbegin() + 1, down.rend() - 1);
  return up;
}

void solve()
{
  int n;
  cin >> n;
  vector<Point<ll>> a(n);
  int id = 0;
  for (auto &x : a)
  {
    cin >> x;
    x.id = ++id;
  }
  auto ch = convex_hull<true>(a);
  sort(all(ch), [](const Point<ll> &a, const Point<ll> &b) { return a.id < b.id; });
  for (auto p : ch) cout << p.id << ' ';
  cout << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}
