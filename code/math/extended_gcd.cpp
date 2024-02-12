/* Extended Euclidean Algorithm
 * Finds x, y such that
 * a * x + b * y = gcd(a, b)
 * Returns gcd
 */
template <typename T> T egcd(T a, T b, T &x, T &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  T x1, y1;
  auto d = egcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
