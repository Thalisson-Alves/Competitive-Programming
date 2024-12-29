namespace rng {
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  inline void set_seed(int seed) { mt.seed(seed); }
  template <typename T> T gen() { return gen(numeric_limits<T>::min(), numeric_limits<T>::max()); }
  template <typename T> T gen(T l, T r) {
    if constexpr (is_integral<T>::value) return uniform_int_distribution<T>(l, r)(mt);
    else if constexpr (is_floating_point<T>::value) return uniform_real_distribution<T>(l, r)(mt);
    else unreachable();
  }
  template<typename T> void shuffle(T first, T last) { std::shuffle(first, last, mt); }
  template<typename T> void shuffle(T &v) { shuffle(v.begin(), v.end()); }
  template<typename T> T choose(const auto &v) { return *next(v.begin(), gen(0, (int)v.size()-1)); }
  vector<int> index_sample(int n, int k) {
    assert(n >= k);
    constexpr int MAGIC = 300;
    if (n < MAGIC or n/MAGIC < k) {
      vector<int> res(n);
      iota(res.begin(), res.end(), 0);
      shuffle(res);
      res.resize(k);
      return res;
    } else {
      vector<int> res(k);
      unordered_set<int> used(k);
      for (int i = 0; i < k; i++) {
        while (!used.insert(res[i] = gen(0, n-1)).second);
      }
      return res;
    }
  }
  template<typename T> vector<T> sample(const auto &v, int k) {
    k = min(k, (int)v.size());
    vector<T> res(k);
    auto idx = index_sample((int)v.size(), k);
    for (int i = 0; i < k; i++) res[i] = v[idx[i]];
    return res;
  }
}
