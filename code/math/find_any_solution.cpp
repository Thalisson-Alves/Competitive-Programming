/* Finds any solution to the equation
* (a * x0) + (b * y0) = c
* g = gcd(a, b)
* Returns true if solution exists
*/
template <typename T> bool find_any_solution(T a, T b, T c, T &x0, T &y0, T &g) {
  g = egcd(abs(a), abs(b), x0, y0);
  if (c % g) return false;

  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}
