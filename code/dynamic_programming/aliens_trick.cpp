/* Aliens Trick Optimization
 *
 * In general, "aliens trick" allows you to get rid of
 * the restriction on total number of operations applied
 * by replacing it with the binary search of the value lambda,
 * the lambda is the cost of applying one operation.
 *
 * The function f is the DP that you want to optimize.
 * It should receive lambda (the cost of applying one operation)
 * as a parameter, and return a pair of values, the first value
 * is the cost of the DP, and the second value is the number
 * of operations applied.
 *
 * It only works if the DP is convex, which means that the
 * cost of the DP is a convex function regarding the number
 * of operations applied.
 *
 * dp(x, k) - dp(x, k+1) more optimal than dp(x, k+1) - dp(x, k+2)
 */
auto aliens_trick(auto &&f, ll k, ll r=INT_MAX) {
  ll l = 0;
  while (l <= r) {
    ll mid = midpoint(l, r);
    if (f(mid).second > k) l = mid + 1;
    else r = mid - 1;
  }
  return f(l).first - k * l;
};
