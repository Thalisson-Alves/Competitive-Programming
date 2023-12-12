template<typename T>
T polygon_area(const vector<Point<T>> &pts) {
  T res = 0;
  for (int i = 2; i < (int)pts.size(); i++) {
    res += pts[0].cross(pts[i-1], pts[i]);
  }
  return abs(res) / 2;
}

template<typename T>
ll boundary_points(const vector<Point<T>> &pts) {
  ll res = 0;
  for (int i = 0; i < (int)pts.size() - 1; i++) {
    res += gcd(abs(pts[i].x - pts[i+1].x), abs(pts[i].y - pts[i+1].y));
  }
  res += gcd(abs(pts.back().x - pts[0].x), abs(pts.back().y - pts[0].y));
  return res;
}

template<typename T>
pair<ll, ll> lattice_points(const vector<Point<T>> &pts) {
  ll b = boundary_points(pts);
  ll a = polygon_area(pts);
  return {a - b / 2 + 1, b};
}
