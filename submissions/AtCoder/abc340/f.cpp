#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

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

void solve()
{
  ll a, b;
  cin >> a >> b;
  ll x, y, g;
  if (!find_any_solution(b, -a, 2ll, x, y, g))
    cout << "-1\n";
  else
    cout << x << ' ' << y << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
