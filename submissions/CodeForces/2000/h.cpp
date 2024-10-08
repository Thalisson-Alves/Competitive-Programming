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
    if (r < tl or tr < l) return id;
    if (l <= tl and tr <= r) return node->value;
    extend(node);
    auto tm = tl + (tr - tl) / 2;
    return op(query(node->l, l, r, tl, tm), query(node->r, l, r, tm+1, tr));
  }
  int pos(unique_ptr<Node> &node, int tl, int tr, const auto &f, T acc) {
    if (tl == tr) return tl;
    extend(node);
    auto tm = tl + (tr - tl) / 2;
    if (f(op(acc, node->l->value))) return pos(node->l, tl, tm, f, acc);
    return pos(node->r, tm+1, tr, f, op(acc, node->l->value));
  }
public:
  void set(int idx, const T x) { update<1>(root, idx, x, range.first, range.second); }
  void update(int idx, const T x) { update<0>(root, idx, x, range.first, range.second); }
private:
  template<bool is_setting> void update(unique_ptr<Node> &node, int idx, const T x, int tl, int tr) {
    if (tl == tr) {
      if constexpr (is_setting) node->value = x;
      else node->value = op(node->value, x);
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

struct Nothing {};
template<typename T, typename D=Nothing, typename F=function<void(T,T,D)>, typename R=F, typename U=function<void(T,T,T,D)>>
struct BlockSet {
  map<T, pair<T, D>> blocks;
  function<void(T,T,D)> fset, frem;
  function<void(T,T,T,D)> fupd;
  BlockSet(F s, R r, U u) : fset(s), frem(r), fupd(u) {}
  void merge(T l, T r) {
    auto it = blocks.upper_bound(l);
    if (it == end(blocks)) return;
    if (it == begin(blocks)) ++it;
    while (it != end(blocks) and it->first <= r) {
      auto il = prev(it);
      auto ir = it++;
      if (il->second.first >= l) merge(il, ir);
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
  void add(T l, T r) {
    add_unchecked(l, r);
    merge(l, r);
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

void solve() {
  int n;
  cin >> n;
  SparseSegTree<int> seg(0, 2e6, [](int a, int b) { return max(a, b); });
  auto fset = [&](int l, int r, auto) { seg.set(l, r-l+1); };
  auto frem = [&](int l, int, auto) { seg.set(l, 0); };
  auto fupd = [&](int l, int r, int, auto) { seg.set(l, r-l+1); };
  BlockSet<int, Nothing> bs(fset, frem, fupd);
  bs.add_unchecked(1, 2e6);
  set<int> gap;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    bs.remove(x, x);
    gap.insert(x);
  }
  int q; cin >> q;
  while (q--) {
    char c; int x;
    cin >> c >> x;
    if (c == '-') bs.add_unchecked(x, x), bs.merge(x-1, x+1), gap.erase(x);
    else if (c == '+') bs.remove(x, x), gap.insert(x);
    else {
      auto res = seg.pos([&](int k) { return k >= x; });
      cout << (~res ? res : *rbegin(gap)+1) << ' ';
    }
  }
  cout << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
