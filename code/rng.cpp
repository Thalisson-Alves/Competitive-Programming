namespace rng {
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  uniform_real_distribution<double> dist(0.0, 1.0);

  inline void set_seed(int seed) { mt.seed(seed); }

  inline double next_double() { return dist(mt); }
  inline double next_double(double l, double r) { return l + (r - l) * next_double(); }
  inline int next_int(int n) { return mt() % n; }
  inline int next_int(int l, int r) { return l + mt() % (r - l + 1); }

  template<typename T> inline void shuffle(vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
      int j = next_int(i, (int)v.size() - 1);
      swap(v[i], v[j]);
    }
  }

  template<typename T> inline T choose(const vector<T> &v) { return v[next_int((int)v.size())]; }
  template<typename T> inline T choose(const initializer_list<T> &v) { return *next(v.begin(), next_int((int)v.size())); }

  template<typename T> inline vector<T> sample(const vector<T> &v, int k) {
    vector<int> idx((int)v.size());
    iota(idx.begin(), idx.end(), 0);
    shuffle(idx);
    vector<T> ans(k);
    for (int i = 0; i < k; i++) ans[i] = v[idx[i]];
    return ans;
  }
}
