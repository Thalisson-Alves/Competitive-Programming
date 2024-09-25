#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

mt19937 rng((long) chrono::steady_clock::now().time_since_epoch().count());
template <typename T, auto op, typename L, auto mapping, auto composition>
struct ImplicitTreap {
  struct Node {
    T key, acc;
    L lazy;
    int priority, size;
    bool rev;
    Node *l, *r;
    Node(T value, int prior) : key(value), acc(value), lazy(L()), priority(prior), size(1), rev(false), l(), r() {}
    Node(T value) : Node(value, (int)rng()) {}
    ~Node() { delete l; delete r; }
    void prop() {
      if (lazy) {
        key = mapping(lazy, key, 1);
        acc = mapping(lazy, acc, size);
        if (l) l->lazy = composition(lazy, l->lazy);
        if (r) r->lazy = composition(lazy, r->lazy);
      }
      if (rev) {
        swap(l, r);
        if (l) l->rev ^= 1;
        if (r) r->rev ^= 1;
      }
      lazy = L(); rev = 0;
    }
    void update() {
      size = 1, acc = key;
      if (l) l->prop(), size += l->size, acc = op(l->acc, acc);
      if (r) r->prop(), size += r->size, acc = op(acc, r->acc);
    }
  };
  using ptr = Node*;
  ptr root;
  ImplicitTreap() : root() {}
  ImplicitTreap(const ImplicitTreap &o) = delete;
  ~ImplicitTreap() { delete root; }
  int size(ptr t) const { return (t ? t->size : 0); }
  int size() const { return size(root); }
  T query(ptr t) const { return (t ? t->acc : T()); }
  T query() const { return query(root); }
  ptr merge(ptr l, ptr r) {
    if (!l or !r) return l ? l : r;
    l->prop(), r->prop();
    if (l->priority > r -> priority) return l->r = merge(l->r, r), l->update(), l;
    else return r->l = merge(l, r->l), r->update(), r;
  }
  pair<ptr, ptr> split_at(ptr t, int pos) {
    if (!t) return {};
    t->prop();
    pair<ptr, ptr> res;
    if (size(t->l) >= pos) res = split_at(t->l, pos), t->l = res.second, res = {res.first, t};
    else res = split_at(t->r, pos-size(t->l)-1), t->r = res.first, res = {t, res.second};
    t->update();
    return res;
  }
  pair<ptr, ptr> split_less(ptr t, T key) {
    if (!t) return {};
    t->prop();
    pair<ptr, ptr> res;
    if (t->key >= key) res = split_less(t->l, key), t->l = res.second, res = {res.first, t};
    else res = split_less(t->r, key), t->r = res.first, res = {t, res.second};
    t->update();
    return res;
  }
  T query(int l, int r) {
    auto p1 = split_at(root, l);
    auto p2 = split_at(p1.second, r-l+1);
    T res = query(p2.first);
    root = merge(merge(p1.first, p2.first), p2.second);
    return res;
  }
  T get(int pos) {
    assert(pos < size(root));
    auto p1 = split_at(root, pos);
    auto p2 = split_at(p1.second, 1);
    T res = p2.first->key;
    root = merge(merge(p1.first, p2.first), p2.second);
    return res;
  }
  void set(int pos, T s) {
    assert(pos < size(root));
    auto p1 = split_at(root, pos);
    auto p2 = split_at(p1.second, 1);
    p2.first->prop();
    p2.first->key = s;
    p2.first->update();
    root = merge(merge(p1.first, p2.first), p2.second);
  }
  void update(int l, int r, L s) {
    auto p1 = split_at(root, l);
    auto p2 = split_at(p1.second, r-l+1);
    if (p2.first) p2.first->lazy = composition(s, p2.first->lazy);
    root = merge(merge(p1.first, p2.first), p2.second);
  }
  T query_pref(int r) {
    auto p = split_at(root, r+1);
    T res = query(p.first);
    root = merge(p.first, p.second);
    return res;
  }
  void insert_at(int pos, T value) {
    auto p = split_at(root, pos);
    ptr node = new Node(value);
    root = merge(merge(p.first, node), p.second);
  }
  void insert(T key) {
    auto p = split_less(root, key);
    ptr node = new Node(key);
    root = merge(merge(p.first, node), p.second);
  }
  int count(T key) {
    auto p1 = split_less(root, key);
    auto p2 = split_less(p1.second, key+1);
    int res = size(p2.first);
    root = merge(merge(p1.first, p2.first), p2.second);
    return res;
  }
  int count_less(T key) {
    auto p = split_less(root, key);
    int res = size(p.first);
    root = merge(p.first, p.second);
    return res;
  }
  void push_back(T key) { root = merge(root, new Node(key)); }
  void remove_at(int pos) { remove_range(pos, pos); }
  void remove_range(int l, int r) {
    auto p1 = split_at(root, l);
    auto p2 = split_at(p1.second, r-l+1);
    delete p2.first;
    root = merge(p1.first, p2.second);
  }
  void remove(T key) {
    auto p1 = split_less(root, key);
    auto p2 = split_less(p1.second, key + 1);
    delete p2.first;
    root = merge(p1.first, p2.second);
  }
  void swap_non_overlapping(int l1, int r1, int l2, int r2) {
    if (l1 > l2) swap(l1, l2), swap(r1, r2);
    assert(l1 < l2 and r1 < l2);
    auto p1 = split_at(root, l1);
    auto p2 = split_at(p1.second, r1-l1+1);
    auto p3 = split_at(p2.second, l2-r1-1);
    auto p4 = split_at(p3.second, r2-l2+1);
    root = merge(merge(merge(merge(p1.first, p4.first), p3.first), p2.first), p4.second);
  }
  void reverse(int l, int r) {
    auto p1 = split_at(root, l);
    auto p2 = split_at(p1.second, r-l+1);
    if (p2.first) p2.first->rev ^= 1;
    root = merge(merge(p1.first, p2.first), p2.second);
  }
  void inorder(auto &&f) const {
    auto dfs = [&](auto &&self, ptr u) -> void {
      if (!u) return;
      u->prop();
      self(self, u->l);
      f(u);
      self(self, u->r);
    };
    dfs(dfs, root);
  }
};
struct Node {
  int pref0, pref1, suf0, suf1, res;
  int cnt0, cnt1;
  Node() : pref0(0), pref1(0), suf0(0), suf1(0), res(0), cnt0(0), cnt1(0) {}
  Node(bool v) : pref0(!v), pref1(v), suf0(!v), suf1(v), res(1), cnt0(!v), cnt1(v) {}
  Node(int a, int b, int c, int d, int e, int f, int g) : pref0(a), pref1(b), suf0(c), suf1(d), res(e), cnt0(f), cnt1(g) {}
};
Node op(Node a, [[maybe_unused]] Node b) {
  return {max(a.pref0, (a.cnt1 == 0 ? a.cnt0 + b.pref0 : 0)), max(a.pref1, (a.cnt0 == 0 ? a.cnt1 + b.pref1 : 0)), max(b.suf0, (b.cnt1 == 0 ? b.cnt0 + a.suf0 : 0)), max(b.suf1, (b.cnt0 == 0 ? b.cnt1 + a.suf1 : 0)), max({a.res, b.res, a.suf1 + b.pref1, a.suf0 + b.pref0}), a.cnt0 + b.cnt0, a.cnt1 + b.cnt1};
}
struct Lazy {
  bool flip = false;
  operator bool() const { // has lazy?
    return flip;
  }
};
Node mapping([[maybe_unused]] Lazy f, Node x, [[maybe_unused]] int size) {
  if (f.flip) {
    swap(x.pref0, x.pref1);
    swap(x.suf0, x.suf1);
    swap(x.cnt0, x.cnt1);
  }
  return x;
}
Lazy composition(Lazy f, [[maybe_unused]] Lazy g) {
  f.flip ^= g.flip;
  return f;
}
using Treap = ImplicitTreap<Node, op, Lazy, mapping, composition>;

void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  Treap treap;
  for (auto c : s) treap.push_back(c-'0');
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      treap.update(--l, --r, {1});
    }
    cout << treap.root->acc.res << '\n';
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
