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
    T key;
    int priority, size;
    bool rev;
    Node *l, *r;
    Node(T value, int prior) : key(value), priority(prior), size(1), rev(false), l(), r() {}
    Node(T value) : Node(value, (int)rng()) {}
    ~Node() { delete l; delete r; }
    void prop() {
      if (rev) {
        swap(l, r);
        if (l) l->rev ^= 1;
        if (r) r->rev ^= 1;
      }
      rev = 0;
    }
    void update() {
      size = 1;
      if (l) l->prop(), size += l->size;
      if (r) r->prop(), size += r->size;
    }
  };
  using ptr = Node*;
  ptr root;
  Treap() : root() {}
  Treap(const Treap &o) = delete;
  ~Treap() { delete root; }
  int size(ptr t) const { return (t ? t->size : 0); }
  int size() const { return size(root); }
  T query(ptr t) const { return (t ? t->sum : 0); }
  T query() const { return query(root); }
  ptr merge(ptr l, ptr r) {
    if (!l or !r) return l ? l : r;
    l->prop(), r->prop();
    if (l->priority > r -> priority) return l->r = merge(l->r, r), l->update(), l;
    else return r->l = merge(l, r->l), r->update(), r;
  }
  pair<ptr, ptr> split(ptr t, int pos) {
    if (!t) return {};
    t->prop();
    pair<ptr, ptr> res;
    if (size(t->l) >= pos) res = split(t->l, pos), t->l = res.second, res = {res.first, t};
    else res = split(t->r, pos-size(t->l)-1), t->r = res.first, res = {t, res.second};
    t->update();
    return res;
  }
  T query(int l, int r) {
    auto p1 = split(root, l);
    auto p2 = split(p1.second, r-l+1);
    T res = query(p2.first);
    root = merge(merge(p1.first, p2.first), p2.second);
    return res;
  }
  T get(int pos) {
    auto p1 = split(root, pos);
    auto p2 = split(p1.second, 1);
    T res = p2.first->key;
    root = merge(merge(p1.first, p2.first), p2.second);
    return res;
  }
  void set(int pos, T s) {
    auto p1 = split(root, pos);
    auto p2 = split(p1.second, 1);
    p2.first->key = s;
    root = merge(merge(p1.first, p2.first), p2.second);
  }
  void update(int l, int r, T s) {
    auto p1 = split(root, l);
    auto p2 = split(p1.second, r-l+1);
    p2.first->lazy += s;
    root = merge(merge(p1.first, p2.first), p2.second);
  }
  T query_pref(int r) {
    auto p = split(root, r+1);
    T res = query(p.first);
    root = merge(p.first, p.second);
    return res;
  }
  void insert(int pos, T value) {
    auto p = split(root, pos);
    ptr node = new Node(value);
    root = merge(merge(p.first, node), p.second);
  }
  void push_back(T value) { root = merge(root, new Node(value)); }
  void remove(int pos) {
    auto p1 = split(root, pos);
    auto p2 = split(p1.second, 1);
    delete p2.first;
    root = merge(p1.first, p2.second);
  }
  void reverse(int l, int r) {
    auto p1 = split(root, l);
    auto p2 = split(p1.second, r-l+1);
    p2.first->rev ^= 1;
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
  int n, q;
  cin >> n >> q;
  Treap<char> treap;
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    treap.push_back(c);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    treap.reverse(--l, --r);
  }
  treap.inorder([](auto u) { cout << u->key; });
  cout << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
