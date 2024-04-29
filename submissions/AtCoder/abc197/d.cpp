#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

constexpr double EPS = 1e-9;
template <typename T> bool eq(const T a, const T b) {
  if constexpr (is_floating_point_v<T>) return fabs(a - b) <= EPS;
  else return a == b;
}

const double PI = acos(-1);
double to_rad(double deg) { return deg * PI / 180; }
double to_deg(double rad) { return rad * 180 / PI; }

template<typename T=double> struct Point {
  T x, y;

  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}

  inline Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  inline Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  inline Point operator/(const T &k) const { return Point(x / k, y / k); }
  friend ostream& operator<<(ostream &os, const Point &p) { return os << p.x << ' ' << p.y; }
  friend istream& operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }

  template<typename U> void rotate(U rad) {
    tie(x, y) = make_pair(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
  }
  template<typename U> Point<U> rotated(U rad) const {
    return Point<U>(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
  }
  inline Point to(const Point &p) const { return p - *this; }
};

void solve() {
  int n;
  cin >> n;
  Point<double> a, b;
  cin >> a >> b;
  auto mid = (a + b) / 2;
  auto vet = mid.to(a).rotated(to_rad(360.0/n));
  cout << fixed << setprecision(7) << mid + vet << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
