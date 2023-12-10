/*
 * binary_search(f, l, r) returns the minimum value x in [l, r] such that f(x) is true.
 */
template <typename T, enable_if_t<is_integral_v<T>>> T binary_search(auto f, T l, T r) {
  static_assert(std::is_invocable_r_v<bool, decltype(f), T>, "f must be convertible to std::function<T(T)>");

  while (l <= r) {
    auto mid = midpoint(l, r);
    (f(mid) ? r = mid - 1 : l = mid + 1);
  }
  return l;
}
/*
 * binary_search(f, l, r, max_iter) returns the minimum value x in [l, r] such that f(x) is true.
 */
template <typename T> T binary_search(auto f, T l, T r, int max_iter=100) {
  static_assert(std::is_invocable_r_v<bool, decltype(f), T>, "f must be convertible to std::function<T(T)>");

  while (max_iter--) {
    auto mid = midpoint(l, r);
    (f(mid) ? l : r) = mid;
  }
  return l;
}
/*
 * ternary_search(f, l, r) returns the minimum value x in [l, r] such that f(x) is true.
 * assuming f is of the form false* true+ false*
 * otherwise, returns the last x such that f(x) is true.
 */
template <typename T> T ternary_search(auto f, T l, T r) {
  static_assert(std::is_invocable_r_v<bool, decltype(f), T>, "f must be convertible to std::function<T(T)>");

  while (l <= r) {
    auto m1 = l + (r - l) / 3;
    auto m2 = r - (r - l) / 3;
    if (f(m1)) r = m1 - 1;
    else if (f(m2)) l = m1 + 1, r = m2 - 1;
    else l = m2 + 1;
  }
  return l;
}
