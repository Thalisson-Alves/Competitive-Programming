/* Lazy Polynomial Update
 *
 * Query:
 *  return the sum of values in range [l, r].
 *
 * Update:
 *   increase the first value in range [l, r] by 1,
 *   the second value by 2, the third by 3, and so on.
 */
using Node = ll;
Node op(Node a, Node b) { return a + b; }
struct Lazy {
  ll value;
  int startpos = -1, size = 1;
  ll first(int l) const {
    return value + (l - startpos) * size;
  }
};
Node mapping(Lazy f, Node x, pair<int, int> lr) {
  if (f.startpos == -1) return x;
  auto fst = f.first(lr.first);
  auto lst = f.first(lr.second);
  return x + (lr.second - lr.first + 1) * (fst + lst) / 2;
}
Lazy composition(Lazy f, Lazy g, pair<int, int> lr) {
  if (f.startpos == -1) return g;
  if (g.startpos == -1) return f;
  return {f.first(lr.first) + g.first(lr.first), lr.first, f.size + g.size};
}
