template <typename T = double> struct Segment {
  Point<T> p, q;

  Segment() : p(), q() {}
  Segment(Point<T> a_, Point<T> b_) : p(a_), q(b_) {}

  inline bool operator==(const Segment &l) const {
    return p == l.p and q == l.q;
  }

  inline bool parallel(const Segment &l) const {
    // TODO: handle zero length segments
    return eq(p.cross(q, l.p), (T)0) and eq(p.cross(q, l.q), (T)0);
  }

  inline bool intersects(const Segment &l) const {
    if (parallel(l)) {
      return intersects(l.p) or intersects(l.q) or l.intersects(p) or
             l.intersects(q);
    }
    return orientation(p, q, l.p) * orientation(p, q, l.q) <= 0 and
           orientation(l.p, l.q, p) * orientation(l.p, l.q, q) <= 0;
  }

  inline bool intersects(const Point<T> &r) const {
    return eq(p.cross(q, r), (T)0) and min(p, q) <= r and r <= max(p, q);
  }
  optional<Point<T>> intersection(const Point<T> &r) const {
    if (intersects(r))
      return r;
    return {};
  }

  inline optional<Segment<T>> intersection(const Segment &l) const {
    if (!intersects(l))
      return {};
    if (parallel(l)) {
      return Segment(max(min(p, q), min(l.p, l.q)),
                     min(max(p, q), max(l.p, l.q)));
    }
    if (auto pt = Line<T>(p, q).intersection(Line<T>(l.p, l.q)))
      return Segment(*pt, *pt);
    return {};
  }

  inline Point<T> closest(const Point<T> &r) const {
    if ((r - p).dot(q - p) < EPS) return p;
    if ((r - q).dot(p - q) < EPS) return q;

    return p + (q - p) * ((r - p).dot(q - p) / (q - p).dist2());
  }

  inline double dist2(const Point<T> &r) const { return (r-closest(r)).dist2(); }
  inline double dist(const Point<T> &r) const { return sqrt(dist2(r)); }

  bool operator<(const Segment &l) const {
    if (p.x < l.p.x) return p.to(q).cross(p.to(l.p)) < 0;
    else return l.p.to(l.q).cross(l.p.to(p)) > 0;
  }

  friend ostream& operator<<(ostream &os, const Segment &l) { return os << l.p << ' ' << l.q; }
  friend istream& operator>>(istream &is, Segment &l) { return is >> l.p >> l.q; }
};

template <typename T> void sort_segments(vector<Segment<T>> &segments) {
  sort(segments.begin(), segments.end(), [](const auto &a, const auto &b) {
    return a.a.x < b.a.x;
  });

  vector<vector<int>> g(segments.size()+1);
  set<pair<Segment<T>, int>> st;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> events;

  for (int i = 0; i < (int)segments.size(); i++) {
    while (not events.empty() and events.top().first < segments[i].a.x) {
      auto [x, y] = events.top();
      events.pop();
      st.erase({segments[y], y});
    }

    auto it = st.insert({segments[i], i}).first;
    g[it == st.begin() ? segments.size() : prev(it)->second].push_back(i);
    events.push({segments[i].b.x, i});
  }

  stack<int> dfs;
  dfs.push((int)segments.size());
  vector<Segment<T>> res;

  while (not dfs.empty()) {
    auto u = dfs.top();
    dfs.pop();

    if (u != (int)segments.size()) res.push_back(segments[u]);
    for (auto v : g[u]) dfs.push(v);
  }

  swap(segments, res);
}
