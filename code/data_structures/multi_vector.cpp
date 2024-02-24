template<typename T, int D> struct Vec : public vector<Vec<T, D - 1>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template<typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<T, D - 1>>(n, Vec<T, D - 1>(args...)) {
  }
};
template<typename T>
struct Vec<T, 1> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
  }
};
