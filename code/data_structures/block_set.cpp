/* BlockSet
 *
 * A data structure that maintains a set of disjoint intervals.
 * It supports adding, removing, and merging intervals.
 *
 * Methods:
 * - add(l, r): Add the interval [l, r] to the set.
 *   - merging with existing intervals if necessary.
 *   - Complexity: O(log(n) + k), where n is the number of intervals and k is the number of intervals merged.
 * - remove(l, r): Remove the interval [l, r] from the set.
 *   - splitting existing intervals if necessary.
 *   - Complexity: O(log(n) + k), where n is the number of intervals and k is the number of intervals removed.
 * - merge(l, r): Merge the interval [l, r] with existing intervals.
 *   - Complexity: O(log(n) + k), where n is the number of intervals and k is the number of intervals merged.
 *
 * It's only necessary to implement the Info struct.
 * The Info struct must have the following methods:
 * - shrink_left(l, r, pl): Shrink the interval [pl, r] to [l, r].
 * - shrink_right(l, r, pr): Shrink the interval [l, pr] to [l, r].
 * - insert(l, r): Insert the interval [l, r].
 * - remove(l, r): Remove the interval [l, r].
 * - split(l, r, sl, sr): Split the interval [l, r] into [l, sl-1] and [sr+1, r].
 * - merge(li, ri, lj, rj): Merge the intervals [li, ri] and [lj, rj].
 */
template<typename T, typename F>
struct BlockSet {
  map<T, T> blocks;
  F &f;
  BlockSet(F &f_) : f(f_) {}
  void merge(T l, T r) {
    auto it = blocks.upper_bound(l);
    if (it == end(blocks)) return;
    if (it == begin(blocks)) ++it;
    while (it != end(blocks) and it->first <= r) {
      auto il = prev(it);
      auto ir = it++;
      if (il->second >= l) merge(il, ir);
    }
  }
  void remove(T l, T r) {
    auto it = blocks.upper_bound(l);
    if (it != begin(blocks)) --it;
    if (it == end(blocks) or it->first > r) return;
    if (it->first < l and r < it->second) {
      split(it, l, r);
      return;
    }
    if (it->first < l) shrink_right(it++, l-1);
    while (it != end(blocks) and it->second <= r) remove(it++);
    if (it != end(blocks) and it->first <= r) shrink_left(it, r+1);
  }
  void add(T l, T r) {
    add_unchecked(l, r);
    merge(l, r);
  }
  void add_unchecked(T l, T r) {
    auto it = blocks.find(l);
    if (it == end(blocks)) f.insert(l, r), blocks[l] = r;
    else f.shrink_right(l, r, it->second), it->second = r;
  }
private:
  void insert(T l, T r) {
    assert(!blocks.count(l));
    f.insert(l, r);
    blocks[l] = r;
  }
  void shrink_left(auto it, int l) {
    auto [pl, r] = *it;
    f.shrink_left(l, r, pl);
    blocks.erase(it);
    blocks[l] = r;
  }
  void shrink_right(auto it, int r) {
    f.shrink_right(it->first, r, it->second);
    it->second = r;
  }
  void remove(auto it) {
    f.remove(it->first, it->second);
    blocks.erase(it);
  }
  void split(auto it, T il, T ir) {
    auto [l, r] = *it;
    f.split(l, r, il, ir);
    it->second = il-1;
    blocks[ir+1] = r;
  }
  void merge(auto il, auto ir) {
    auto [li, ri] = *il;
    auto [lj, rj] = *ir;
    f.merge(li, ri, lj, rj);
    il->second = rj;
    blocks.erase(ir);
  }
};
struct Info {
  vector<int> cs;
  vector<int> hist;
  void shrink_left(int l, int r, int pl) {
    cs[l] = cs[pl];
    cs[pl] = -1;
    hist[cs[l]] += (r-l+1)-(r-pl+1);
  }
  void shrink_right(int l, int r, int pr) {
    hist[cs[l]] += (r-l+1)-(pr-l+1);
  }
  void insert(int l, int r) {
    hist[cs[l]] += r-l+1;
  }
  void remove(int l, int r) {
    hist[cs[l]] -= r-l+1;
    cs[l] = -1;
  }
  void split(int l, int r, int sl, int sr) {
    assert(l < sr and sr < r);
    hist[cs[l]] -= sr-sl+1;
    cs[sr+1] = cs[l];
  }
  void merge(int li, int ri, int lj, int rj) {
  }
};
