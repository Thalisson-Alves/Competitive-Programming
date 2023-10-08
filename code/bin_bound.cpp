template<typename T, auto f, auto comp> inline T bin_bound(T x, T l = 0, T r = 1e18) {
  static_assert(std::is_convertible_v<decltype(f), std::function<T(T)>>,
                "f must be convertible to std::function<T(T)>");
  static_assert(std::is_convertible_v<decltype(comp), std::function<bool(T,T)>>,
                "comp must be convertible to std::function<bool(T,T)>");

  while (comp(l, r)) {
    auto mid = l + (r - l) / 2;
    if (comp(f(mid), x)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return r;
}

template<typename T, auto f> inline T lower_bound(T x, T l = 0, T r = 1e18) { return bin_bound<T, f, (less<T>())>(x, l, r); }
template<typename T, auto f> inline T upper_bound(T x, T l = 0, T r = 1e18) { return bin_bound<T, f, (less_equal<T>())>(x, l, r); }
