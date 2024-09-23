#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

mt19937 rng((long) chrono::steady_clock::now().time_since_epoch().count());
template <typename T> struct Treap {
  struct Node {
    T key, sum, pref, suf, res, lazy;
    int priority, size;
    bool rev;
    Node *l, *r;
    Node(T value, int prior) : key(value), sum(value), pref(value), suf(value), res(value), lazy(0), priority(prior), size(1), rev(false), l(), r() {}
    Node(T value) : Node(value, (int)rng()) {}
    ~Node() { delete l; delete r; }
    void prop() {
      if (lazy) {
        key += lazy, sum += lazy*size;
        if (l) l->lazy += lazy;
        if (r) r->lazy += lazy;
      }
      if (rev) {
        swap(l, r);
        if (l) l->rev ^= 1;
        if (r) r->rev ^= 1;
      }
      lazy = rev = 0;
    }
    void update() {
      size = 1, sum = key, res = key, pref = key, suf = key;
      #define G(p, prop, def) ((p) ? p->prop : def)
      if (l) l->prop(), size += l->size, sum += l->sum;
      if (r) r->prop(), size += r->size, sum += r->sum;
      pref = max({G(l, pref, INT_MIN), G(l, sum, 0) + key, G(l, sum, 0) + key + G(r, pref, 0)});
      suf = max({G(r, suf, INT_MIN), G(r, sum, 0) + key, G(r, sum, 0) + key + G(l, suf, 0)});
      res = max({G(l, res, INT_MIN), key, G(r, res, INT_MIN), pref, suf, G(l, suf, 0) + key, key + G(r, pref, 0), G(l, suf, 0) + key + G(r, pref, 0)});
    }
  };
  using ptr = Node*;
  ptr root;
  Treap() : root() {}
  Treap(const Treap &o) = delete;
  ~Treap() { delete root; }
  int size(ptr t) const { return (t ? t->size : 0); }
  int size() const { return size(root); }
  T query(ptr t) const { return (t ? t->res : 0); }
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
  void update(int l, int r, T s) {
    auto p1 = split_at(root, l);
    auto p2 = split_at(p1.second, r-l+1);
    if (p2.first) p2.first->lazy += s;
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
  void remove_at(int pos) {
    auto p1 = split_at(root, pos);
    auto p2 = split_at(p1.second, 1);
    delete p2.first;
    root = merge(p1.first, p2.second);
  }
  void remove(T key) {
    auto p1 = split_less(root, key);
    auto p2 = split_less(p1.second, key + 1);
    delete p2.first;
    root = merge(p1.first, p2.second);
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

void solve() {
  int n;
  cin >> n;
  Treap<ll> treap;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    treap.push_back(x);
  }
  int q; cin >> q;
  while (q--) {
    char t; int x;
    cin >> t >> x;
    --x;
    if (t == 'I') {
      int y; cin >> y;
      treap.insert_at(x, y);
    } else if (t == 'D') {
      treap.remove_at(x);
    } else if (t == 'R') {
      int y; cin >> y;
      treap.set(x, y);
    } else {
      int y; cin >> y, --y;
      cout << treap.query(x, y) << '\n';
    }
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
