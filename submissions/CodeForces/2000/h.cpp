#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

#define F(exp) [](auto a, auto b) { return exp; }
template <typename T, typename Op = T(*)(T,T)> struct SparseSegTree {
  struct Node {
    T value;
    unique_ptr<Node> l, r;
  };

  unique_ptr<Node> root;
  const Op op;
  const T id;
  const pair<int, int> range;

  SparseSegTree(int l, int r, Op f = Op(), T id_ = T()) : root(make_unique<Node>(id_)), op(f), id(id_), range(l, r) { }

  T query(int idx) { return query(idx, idx); }
  T query(int l, int r) { return query(root, l, r, range.first, range.second); }
  int pos(const auto &f) {
    if (!f(root->value)) return -1;
    return pos(root, range.first, range.second, f, id);
  }

private:
  T query(unique_ptr<Node> &node, int l, int r, int tl, int tr) {
    if (r < tl or tr < l)
      return id;

    if (l <= tl and tr <= r)
      return node->value;

    extend(node);
    auto tm = tl + (tr - tl) / 2;
    return op(query(node->l, l, r, tl, tm), query(node->r, l, r, tm+1, tr));
  }
  int pos(unique_ptr<Node> &node, int tl, int tr, const auto &f, T acc) {
    if (tl == tr)
      return tl;

    extend(node);
    auto tm = tl + (tr - tl) / 2;
    if (f(op(acc, node->l->value)))
      return pos(node->l, tl, tm, f, acc);
    return pos(node->r, tm+1, tr, f, op(acc, node->l->value));
  }

public:
  void set(int idx, const T x) { update<1>(root, idx, x, range.first, range.second); }
  void update(int idx, const T x) { update<0>(root, idx, x, range.first, range.second); }

private:
  template<bool is_setting> void update(unique_ptr<Node> &node, int idx, const T x, int tl, int tr) {
    if (tl == tr) {
      if constexpr (is_setting) {
        node->value = x;
      } else {
        node->value = op(node->value, x);
      }
      return;
    }

    extend(node);
    auto tm = tl + (tr - tl) / 2;
    (idx <= tm
     ? update<is_setting>(node->l, idx, x, tl, tm)
     : update<is_setting>(node->r, idx, x, tm+1, tr));
    node->value = op(node->l->value, node->r->value);
  }

  void extend(unique_ptr<Node> &node) {
    if (node->l) return;
    (node->l = make_unique<Node>())->value = id;
    (node->r = make_unique<Node>())->value = id;
  }
};

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
 * - st: set of points
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
    else remove(it->first);
    for (auto [l, r] : v) add(l, r);
  }
  void merge(T x) {
    auto nxt = blocks.upper_bound(x);
    auto prv = nxt != begin(blocks) ? prev(nxt) : end(blocks);
    T l, r;
    if (prv != end(blocks) and nxt != end(blocks) and prv->second + 1 == nxt->first - 1) {
      l = prv->first, r = nxt->second;
      remove(nxt->first);
    } else if (prv != end(blocks) and prv->second + 1 == x) {
      l = prv->first, r = x;
    } else if (nxt != end(blocks) and nxt->first - 1 == x) {
      l = x, r = nxt->second;
      remove(nxt->first);
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
    seg.set(l, 0);
    blocks.erase(l);
  }
};

void solve() {
  int n;
  cin >> n;
  BlockSet<int> bs(1, 2e6);
  bs.add(1, 2e6);
  set<int> gap;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    bs.split(x);
    gap.insert(x);
  }
  int q; cin >> q;
  while (q--) {
    char c; int x;
    cin >> c >> x;
    if (c == '-') bs.merge(x), gap.erase(x);
    else if (c == '+') bs.split(x), gap.insert(x);
    else {
      auto res = bs.query(x);
      cout << (~res ? res : *rbegin(gap)+1) << ' ';
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
