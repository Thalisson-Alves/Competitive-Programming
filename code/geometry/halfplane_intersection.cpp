template <typename T> using Halfplane = pair<Point<T>, Point<T>>;
template <typename T> bool out(const Halfplane<T> &h, const Point<T> &p) {
  return h.second.cross(p - h.first) < 0;
}
template <typename T> Point<long double> inter(const Halfplane<T> &s, const Halfplane<T> &t) {
  long double alpha = (t.first - s.first).cross(t.second) / (long double)s.second.cross(t.second);
  return (Point<long double>)s.first + ((Point<long double>)s.second * alpha);
}
// h is a pair (p, q) of points representing a half-plane
// such that the area of the half-plane is on the left side of the line p->q
template <typename T> vector<Point<long double>> half_plane_intersection(vector<pair<Point<T>, Point<T>>> h) {
  constexpr T inf = 1e8;
  h.insert(end(h), {
    {{inf, inf}, {-inf, inf}},
    {{-inf, inf}, {-inf, -inf}},
    {{-inf, -inf}, {inf, -inf}},
    {{inf, -inf}, {inf, inf}},
  });
  for (auto &[a, b] : h) b -= a;
  if constexpr (is_integral_v<T>) sort(begin(h), end(h), [](const auto &a, const auto &b) { return polar_less(a.second, b.second); });
  else sort(begin(h), end(h), [](const auto &a, const auto &b) { return a.second.angle() < b.second.angle(); });
  deque<Halfplane<T>> dq;
  for (int i = 0; i < (int)size(h); i++) {
    while (size(dq) > 1 and out({h[i].first, h[i].second}, inter(rbegin(dq)[0], rbegin(dq)[1]))) dq.pop_back();
    while (size(dq) > 1 and out({h[i].first, h[i].second}, inter(dq[0], dq[1]))) dq.pop_front();
    if (size(dq) and eq(h[i].second.cross(rbegin(dq)[0].second), (T)0)) {
      if (h[i].second.dot(rbegin(dq)[0].second) < 0) return {};
      if (out(h[i], rbegin(dq)[0].first)) dq.pop_back();
      else continue;
    }
    dq.push_back(h[i]);
  }
  while (size(dq) > 2 and out({dq[0].first, dq[0].second}, inter(rbegin(dq)[0], rbegin(dq)[1]))) dq.pop_back();
  while (size(dq) > 2 and out({rbegin(dq)->first, rbegin(dq)->second}, inter(dq[0], dq[1]))) dq.pop_front();
  if (size(dq) < 3) return {};
  vector<Point<long double>> res(size(dq));
  for (int i = 0; i < (int)size(dq)-1; i++) res[i] = inter(dq[i], dq[i+1]);
  res.back() = inter(*rbegin(dq), dq[0]);
  return res;
}
