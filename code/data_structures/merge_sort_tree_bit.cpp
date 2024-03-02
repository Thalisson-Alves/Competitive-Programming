/* Merge Sort Tree with BIT
 *
 * Stores a `ordered_multiset` in each node of the merge sort tree.
 *
 * Methds:
 * - build(arr): builds the merge sort tree from the array `arr`.
 *   - O(n log^2 n)
 * - add(i, x): adds the element `x` to the `i`-th position of the array.
 *   - O(log^2 n)
 * - update(i, old_value, new_value): updates the `i`-th position of the array from `old_value` to `new_value`.
 *   - O(log^2 n)
 * - query(i, x): number of elements in [0, i] less than `x`.
 *   - O(log^2 n)
 * - query(l, r, x): number of elements in [l, r] less than `x`.
 *   - O(log^2 n)
 * - kth(l, r, k, lo, hi): k-th smallest element in [l, r].
 *   - O(log^3 n)
 *
 * Tested on:
 * - https://www.codechef.com/problems/GIVEAWAY
 * - https://www.spoj.com/problems/GIVEAWAY/
 */
template <typename T> struct MergeSortTreeBIT {
  #define midpoint(l, r) (l + (r - l) / 2)
  int N;
  vector<ordered_multiset<T>> bit;

  MergeSortTreeBIT(int n) : N(n + 1), bit(N + 1) { }
  MergeSortTreeBIT(const vector<T> &arr) : MergeSortTreeBIT((int)arr.size()) {
    build(arr);
  }

  void build(const vector<T> &arr) {
    for (int i = 0; i < N - 1; i++)
      add(i, arr[i]);
  }

  void add(int i, T x) {
    assert(0 <= i && i < N-1);
    for (++i; i <= N; i += (i & -i))
      bit[i].insert(x);
  }

  void update(int i, T old_value, T new_value) {
    assert(0 <= i && i < N-1);
    for (++i; i <= N; i += (i & -i)) {
      bit[i].erase(bit[i].upper_bound(old_value));
      bit[i].insert(new_value);
    }
  }

  // number of elements in [0, i] less than x
  int query(int i, T x) {
    assert(i < N-1);
    int res = 0;
    for (++i; i > 0; i -= (i & -i))
      res += (int)bit[i].order_of_key(x);
    return res;
  }
  // number of elements in [l, r] less than x
  int query(int l, int r, T x) {
    return query(r, x) - query(l-1, x);
  }

  T kth(int l, int r, int k, T lo=numeric_limits<T>::min(), T hi=numeric_limits<T>::max()) {
    assert(0 <= k && k < r-l+1);
    while (lo <= hi) {
      auto mid = midpoint(lo, hi);
      auto cnt = query(l, r, mid);
      if (cnt <= k) lo = mid+1;
      else hi = mid-1;
    }
    return hi;
  }
};
