/* BlockSet
 *
 * A set of blocks (intervals) that supports the following operations:
 * - split(x): split the block containing x into two blocks
 * - merge(x): merge the block neighboring x
 * - query(k): find the first block with size at least k
 * - add(l, r): add a block [l, r]
 * - remove(l): remove the block starting at l
 *
 * Fields:
 * - blocks: map of blocks
 *   - key: start of block
 *   - value: end of block
 * - seg: sparse segment tree
 *
 * Complexity: O(log n) per operation
*/
template<typename T> struct BlockSet {
  map<T, T> blocks;
  SparseSegTree<T> seg;

  BlockSet(T mn, T mx) : seg(mn, mx, F(max(a,b))) {}

  void split(T x) {
    auto it = blocks.upper_bound(x);
    if (it == begin(blocks)) return;
    it = prev(it);
    vector<pair<T, T>> v;
    v.reserve(2);
    if (it->second > x) v.emplace_back(x+1, it->second);
    if (it->first < x) v.emplace_back(it->first, x-1);
    else remove(it);
    for (auto [l, r] : v) add(l, r);
  }
  void merge(T x) {
    auto nxt = blocks.upper_bound(x);
    auto prv = nxt != begin(blocks) ? prev(nxt) : end(blocks);
    T l, r;
    if (prv != end(blocks) and nxt != end(blocks) and prv->second + 1 == nxt->first - 1) {
      l = prv->first, r = nxt->second;
      remove(nxt);
    } else if (prv != end(blocks) and prv->second + 1 == x) {
      l = prv->first, r = x;
    } else if (nxt != end(blocks) and nxt->first - 1 == x) {
      l = x, r = nxt->second;
      remove(nxt);
    } else {
      l = x, r = x;
    }
    add(l, r);
  }
  T query(T k) {
    return seg.pos([&](T x) { return x >= k; });
  }
  void add(T l, T r) {
    seg.set(l, r-l+1);
    blocks[l] = r;
  }
  void remove(T l) {
    auto it = blocks.find(l);
    if (it != end(blocks)) remove(it);
  }
private:
  void remove(auto it) {
    seg.set(it->first, 0);
    blocks.erase(it);
  }
};
