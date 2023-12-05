template<typename T, enable_if_t<is_integral_v<T>>> T lower_bound(auto f, T l, T r) {
  static_assert(std::is_invocable_r_v<bool, decltype(f), T>, "f must be convertible to std::function<T(T)>");

  while (l <= r) {
    auto mid = midpoint(l, r);
    (f(mid) ? r = mid - 1 : l = mid + 1);
  }
  return l;
}
template<typename T> T lower_bound(auto f, T l, T r, int max_iter=100) {
  static_assert(std::is_invocable_r_v<bool, decltype(f), T>, "f must be convertible to std::function<T(T)>");

  while (max_iter--) {
    auto mid = midpoint(l, r);
    (f(mid) ? l : r) = mid;
  }
  return l;
}
