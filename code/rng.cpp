namespace rng {
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  uniform_real_distribution<double> dist(0.0, 1.0);

  inline void set_seed(int seed) { mt.seed(seed); }

  inline double next_double() { return dist(mt); }
  inline double next_double(double l, double r) {
    assert(l <= r);
    return l + next_double() * (r - l);
  }
  template<typename T, typename = typename enable_if<is_integral<T>::value>::type> inline T next_int(T r) {
    assert(r > 0);
    return T(mt() % r);
  }
  template<typename T, typename = typename enable_if<is_integral<T>::value>::type> inline T next_int(T l, T r) {
    assert(l <= r);
    return l + (T)(mt() % (r - l + 1));
  }

  template<typename T> inline void shuffle(vector<T> &v) {
    std::shuffle(v.begin(), v.end(), mt);
  }

  template<typename T> inline T choose(const vector<T> &v) { return v[next_int((int)v.size())]; }
  template<typename T> inline T choose(const initializer_list<T> &v) { return *next(v.begin(), next_int((int)v.size())); }

  template<typename T> inline vector<T> sample(const vector<T> &v, int k) {
    k = min(k, (int)v.size());
    vector<int> idx((int)v.size());
    iota(idx.begin(), idx.end(), 0);
    shuffle(idx);
    vector<T> ans(k);
    for (int i = 0; i < k; i++) ans[i] = v[idx[i]];
    return ans;
  }
}
