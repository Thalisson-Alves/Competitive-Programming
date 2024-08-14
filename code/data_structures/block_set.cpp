/* BlockSet
 *
 * A set of disjoint blocks (intervals) contained in range (mn, mx).
 *
 * Fields:
 * - blocks: map of blocks
 *   - key: start of block
 *   - value: end of block
 * - seg: sparse segment tree
 *   - change this to query different things
 *
 * Methods:
 * - add(l, r): Adds block (l, r) and merge with adjacent ones
 *   - O(log(n) + m) where `m` is the number of adjacent blocks
 * - add(x): Same as add(x, x)
 * - remove(l, r): Removes all blocks inside (l, r), splitting edges
 *   - O(log(n) + m) where `m` is the number of blocks in range (l, r)
 * - remove(x): Same as remove(x, x)
 * - remove_block(l): Removes block that starts at l
 *   - O(log(n))
 * - update_block(l, r): Updates block that starts at l to end at r
 *   - O(log(n) + m) where `m` is the number of blocks in range(l, r)
*/
template<typename T> struct BlockSet {
  map<T, T> blocks;
  SparseSegTree<T> seg;

  BlockSet(T mn, T mx) : seg(mn, mx, F(max(a,b))) {}

  void add(T x) { add(x, x); }
  T query(T k) {
    return seg.pos([&](T x) { return x >= k; });
  }
  void add(T l, T r) {
    auto it = blocks.upper_bound(l);
    int close = l, far = r;
    if (it != begin(blocks) and prev(it)->second+1 >= l) {
      close = prev(it)->first;
      far = max(far, prev(it)->second);
    }
    while (it != end(blocks) and it->first-1 <= far) {
      far = max(far, it->second);
      remove_it(it++);
    }
    upsert_unchecked(close, far);
  }
  void remove(T x) { remove(x, x); }
  void remove(T l, T r) {
    auto it = blocks.upper_bound(l);
    if (it != begin(blocks)) --it;
    if (it->first <= l and l <= it->second) {
      auto [close, far] = *it;
      if (close < l) upsert_unchecked(close, l-1), ++it;
      else remove_it(it++);
      if (r < far) upsert_unchecked(r+1, far);
    }
    while (it != end(blocks) and it->second <= r)
      remove_it(it++);
    if (it != end(blocks) and it->first <= r) {
      int far = it->second;
      remove_it(it);
      if (far > r) upsert_unchecked(r+1, far);
    }
  }
  void remove_block(T l) {
    auto it = blocks.find(l);
    if (it != end(blocks)) remove_it(it);
  }
  void update_block(T l, T r) {
    auto it = blocks.find(l);
    if (it == end(blocks) or it->second == r) return;
    if (it->second < r) add(l, r);
    else upsert_unchecked(l, r);
  }
private:
  void remove_it(auto it) {
    seg.set(it->first, 0);
    blocks.erase(it);
  }
  void upsert_unchecked(T l, T r) {
    blocks[l] = r;
    seg.set(l, r-l+1);
  }
};
