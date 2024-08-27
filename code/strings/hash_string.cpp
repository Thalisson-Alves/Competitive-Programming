template<int p1=31, int p2=29, int q1=(int)1e9+7, int q2=(int)1e9+9> struct HashString {
  using H = pair<int, int>;
  static H mul(H a, H b) { return {(ll)a.first*b.first%q1, (ll)a.second*b.second%q2}; }
  static H add(H a, int x) { return {(a.first+x)%q1, (a.second+x)%q2}; }
  static H sub(H a, H b) { return {(a.first-b.first+q1)%q1, (a.second-b.second+q2)%q2}; }
  static inline vector<H> pows{{1, 1}, {p1, p2}};
  static inline H power(int i) {
    while ((int)pows.size() <= i) pows.push_back(mul(pows.back(), pows[1]));
    return pows[i];
  }
  vector<H> pref;
  HashString() : pref(1) {}
  HashString(const auto &s) : HashString() { add(s); }
  void add(int c) { pref.push_back(add(mul(pref.back(), pows[1]), c)); }
  void add(const string &s) {
    reserve_more(s.size());
    for (auto c : s) add(c);
  }
  template <typename T> void add(const vector<T> &s) {
    reserve_more(s.size());
    for (auto c : s) add(c);
  }
  void reserve_more(size_t n) {
    pref.reserve(pref.size() + n);
    pows.reserve(pref.capacity());
  }
  H hash() const { return pref.back(); }
  int size() const { return (int)pref.size() - 1; }
  bool operator<(const HashString &a) const { return hash() < a.hash(); }
  H substr(int l) const { return substr(l, size()-1); }
  H substr(int l, int r) {
    assert(0 <= l and l <= r and r < size());
    return sub(pref[r+1], mul(power(r-l+1), pref[l]));
  }
  int max_prefix(const HashString &h) const {
    int l = 0, r = (int)min(size(),h.size())-1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (substr(0, mid) == h.substr(0, mid)) l = mid + 1;
      else r = mid - 1;
    }
    return l;
  }
  int max_suffix(const HashString &h) const {
    int l = 1, r = (int)min(size(),h.size());
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (substr(size()-mid) == h.substr(h.size()-mid)) l = mid + 1;
      else r = mid - 1;
    }
    return r;
  }
};
