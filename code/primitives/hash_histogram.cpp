template<int p1=(int)2e5+3, int p2=(int)2e5+9, int q1=(int)1e9+7, int q2=(int)1e9+9> struct HashHistogram {
  using H = pair<int, int>;
  static H mul(H a, H b) { return {(ll)a.first*b.first%q1, (ll)a.second*b.second%q2}; }
  static H mul(H a, ll x) { return {(ll)a.first*(x%q1)%q1, (ll)a.second*(x%q2)%q2}; }
  static H add(H a, H b) { return {(a.first+b.first)%q1, (a.second+b.second)%q2}; }
  static H sub(H a, H b) { return {(a.first-b.first+q1)%q1, (a.second-b.second+q2)%q2}; }
  static inline vector<H> pows{{1, 1}, {p1, p2}};
  static inline H power(int i) {
    while ((int)pows.size() <= i) pows.push_back(mul(pows.back(), pows[1]));
    return pows[i];
  }
  vector<H> pref;
  HashHistogram() : pref(1) {}
  HashHistogram(const auto &hist) : HashHistogram() { add(hist); }
  void add(int idx, int x) {
    pref.push_back(add(pref.back(), mul(power(idx), x)));
  }
  template <typename T> void add(const vector<T> &hist) {
    pows.reserve(pows.size() + hist.size());
    auto &res = pref.emplace_back();
    for (int i = 0; i < (int)hist.size(); i++)
      res = add(res, mul(power(i), hist[i]));
  }
  H hash() const { return pref.back(); }
  int size() const { return (int)pref.size() - 1; }
  bool operator<(const HashHistogram &a) const { return hash() < a.hash(); }
  H hash(int l) const { return hash(l, size()-1); }
  H hash(int l, int r) {
    assert(0 <= l and l <= r and r < size());
    return sub(pref[r+1], pref[l]);
  }
};
