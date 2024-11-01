template <typename T, typename Q=T, typename F=function<Q(Q,T)>>
struct FDeque {
  FStack<T, Q, F> l, r, t;
  FDeque(F f = F(), Q e = Q()) : l(f, e), r(f, e), t(f, e) {}
  void rebalance() {
    bool f = false;
    if (r.empty()) l.swap(r), f = 1;
    int sz = (int)r.size() >> 1;
    while (sz--) t.push(r.top()), r.pop();
    while (!r.empty()) l.push(r.top()), r.pop();
    while (!t.empty()) r.push(t.top()), t.pop();
    if (f) l.swap(r);
  }
  auto get(auto &&f) const {
    const auto &lv = l.empty() ? l.e : l.get();
    const auto &rv = r.empty() ? r.e : r.get();
    return f(lv, rv);
  }
  bool empty() const { return l.empty() and r.empty(); }
  int size() const { return l.size() + r.size(); }
  void push_front(T x) { l.push(x); }
  void push_back(T x) { r.push(x); }
  void pop_front() { if (l.empty()) rebalance(); l.pop(); }
  void pop_back() { if (r.empty()) rebalance(); r.pop(); }
  const T &front() { if (l.empty()) rebalance(); return l.top(); }
  const T &back() { if (r.empty()) rebalance(); return r.top(); }
  void swap(FDeque &o) { l.swap(o.l), r.swap(o.r); }
};
