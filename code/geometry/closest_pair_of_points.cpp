template <typename T> pair<int, int> closest_pair_points(const vector<Point<T>> &ps) {
  vector<pair<Point<T>, int>> p(size(ps));
  for (int i = 0; i < (int)size(ps); i++) p[i] = {ps[i], i};
  sort(begin(p), end(p));
  T d2 = numeric_limits<T>::max();
  set<pair<Point<T>, int>> st = {{{p[0].first.y, p[0].first.x}, p[0].second}};
  pair<int, int> res;
  for (int i = 1, j = 0; i < (int)size(p); i++) {
    T dd = (T)ceil(sqrt(d2));
    for (; j < i and p[j].first.x < p[i].first.x-dd; st.erase({{p[j].first.y, p[j].first.x}, p[j].second}), ++j);
    auto l = st.lower_bound({{p[i].first.y-dd, 0}, -1});
    auto r = st.upper_bound({{p[i].first.y+dd, 0}, INT_MAX});
    for (auto it = l; it != r; it++) {
      auto d = p[i].first.dist2({it->first.y, it->first.x});
      if (d < d2) {
        d2 = d;
        res = {p[i].second, it->second};
      }
    }
    st.insert({{p[i].first.y, p[i].first.x}, p[i].second});
  }
  if (res.first > res.second) swap(res.first, res.second);
  return res;
}
template <typename T> T min_dist2(const vector<Point<T>> &ps) {
  auto [i, j] = closest_pair_points(ps);
  return ps[i].dist2(ps[j]);
}
template <typename T> long double min_dist(const vector<Point<T>> &ps) { return sqrtl(min_dist2(ps)); }
