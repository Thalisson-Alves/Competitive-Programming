template <typename T, int K> struct KMajority {
  array<pair<T, int>, K> hist;
  KMajority() { hist.fill({T(), -1}); }
  void add(T x, int cnt) {
    assert(cnt > 0);
    for (auto &[k, c] : hist) if (~c and k == x) {
      c += cnt;
      return;
    }
    for (auto &[k, c] : hist) if (c == -1) {
      k = x, c = cnt;
      return;
    }
    for (auto &[k, c] : hist) if (c < cnt) swap(k, x), swap(c, cnt);
    for (auto &[k, c] : hist) if (!(c -= cnt)) c = -1;
  };
  void merge(const KMajority &km) {
    for (auto [x, y] : km.hist) if (~y) add(x, y);
  }
  static KMajority op(KMajority ka, const KMajority &kb) {
    ka.merge(kb);
    return ka;
  };
};
