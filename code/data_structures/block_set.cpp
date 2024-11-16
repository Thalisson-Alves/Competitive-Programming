/* BlockSet
 *
 * A data structure that maintains a set of disjoint intervals.
 * It supports adding, removing, and merging intervals.
 *
 * Methods:
 * - get(i): Returns the interval that contains i.
 *   - Time complexity: O(log(n)).
 * - update(l, r, v): Updates the interval [l, r] with value v.
 *   - Time complexity: O(log(n)) amortized.
 * - remove(l, r): Remove intervals that overlap with [l, r].
 *   - Split intervals that are partially contained in [l, r].
 *   - Time complexity: O(log(n)) amortized.
 * - merge(l, r): Merge intervals that overlap with [l, r].
 *   - The intervals are only merged if they have the same value v.
 *   - Time complexity: O(log(n)) amortized.
 * - add_unchecked(l, r, v): Add the interval [l, r] with value v.
 *   - Does not merge intervals.
 *   - Time complexity: O(log(n)).
 *
 * Atributes:
 * - blocks: A map from the left endpoint to the right endpoint and value.
 *   - The intervals are stored as [left, right].
 * - fset(l, r, v): A function that sets the interval [l, r] with value v.
 * - frem(l, r, v): A function that removes the interval [l, r] with value v.
 * - fupd(l, r, pr, v): A function that updates the interval [l, pr] to [l, r] with value v.
 *   - pr is the right endpoint of the interval before the update.
 */
struct Nothing {};
template<typename T, typename D=Nothing, typename F=function<void(T,T,D)>, typename R=F, typename U=function<void(T,T,T,D)>>
struct BlockSet {
  map<T, pair<T, D>> blocks;
  function<void(T,T,D)> fset, frem;
  function<void(T,T,T,D)> fupd;
  BlockSet(F s, R r, U u) : fset(s), frem(r), fupd(u) {}
  tuple<T, T, D> get(T i) const {
    auto it = prev(blocks.upper_bound(i));
    return {it->first, it->second.first, it->second.second};
  }
  void merge(T l, T r) {
    auto it = blocks.upper_bound(l);
    if (it == end(blocks)) return;
    if (it == begin(blocks)) ++it;
    while (it != end(blocks) and it->first <= r) {
      auto il = prev(it);
      auto ir = it++;
      if (il->second.first >= l and il->second.second == ir->second.second) merge(il, ir);
    }
  }
  void remove(T l, T r) {
    auto it = blocks.upper_bound(l);
    if (it != begin(blocks)) --it;
    if (it == end(blocks) or it->first > r) return;
    if (it->first < l and r < it->second.first) {
      split(it, l, r);
      return;
    }
    if (it->first < l) shrink_right(it++, l-1);
    while (it != end(blocks) and it->second.first <= r) remove(it++);
    if (it != end(blocks) and it->first <= r) shrink_left(it, r+1);
  }
  void update(T l, T r, D d=D()) {
    remove(l, r);
    add_unchecked(l, r, d);
  }
  void add_unchecked(T l, T r, D d=D()) {
    auto it = blocks.find(l);
    if (it != end(blocks)) remove(it);
    insert(l, r, d);
  }
private:
  void insert(T l, T r, D d) {
    assert(!blocks.count(l));
    fset(l, r, d);
    blocks[l] = {r, d};
  }
  void shrink_left(auto it, int l) {
    insert(l, it->second.first, it->second.second);
    remove(it);
  }
  void shrink_right(auto it, int r) {
    auto [l, rp] = *it;
    fupd(l, r, rp.first, rp.second);
    it->second.first = r;
  }
  void remove(auto it) {
    frem(it->first, it->second.first, it->second.second);
    blocks.erase(it);
  }
  void split(auto it, T il, T ir) {
    auto [r, d] = it->second;
    shrink_right(it, il-1);
    insert(ir+1, r, d);
  }
  void merge(auto il, auto ir) {
    shrink_right(il, ir->second.first);
    remove(ir);
  }
};
