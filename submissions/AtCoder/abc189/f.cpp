#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

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

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;

  vector<char> cant(n+1);
  for (int i = 0, x; i < k; i++) cin >> x, cant[x] = 1;

  vector<Point<double>> dp(n+1);
  Point<double> sum;
  int sum_idx = n;
  int total_cant = 0;

  for (int i = n-1; ~i; --i)
  {
    if (i + m < sum_idx)
    {
      total_cant -= cant[sum_idx];
      sum -= dp[sum_idx--];
    }
    if (i + 1 < n)
    {
      sum += dp[i+1];
      total_cant += cant[i+1];
    }

    if (total_cant == m)
    {
      cout << "-1\n";
      return;
    }

    if (cant[i])
      dp[i] = {0.0, 1.0};
    else
      dp[i] = Point<double>(1, 0) + sum / m;
  }

  if (fabs(1 - dp[0].y) <= 1e-9)
  {
    cout << "-1\n";
    return;
  }

  cout << fixed << setprecision(7) << dp[0].x / (1 - dp[0].y) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
