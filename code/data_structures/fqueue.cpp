template <typename T, typename Q=T, typename F=function<Q(Q,T)>>
struct FQueue {
  FStack<T, Q, F> l, r;
  FQueue(F f = F(), Q e = Q()) : l(f, e), r(f, e) {}
  void push(T x) { l.push(x); }
  void rebalance() {
    if (r.empty()) {
      while (l.size()) {
        r.push(l.top());
        l.pop();
      }
    }
  }
  const T &front() { rebalance(); return r.top(); }
  auto get(auto &&f) const {
    const auto &lv = l.empty() ? l.e : l.get();
    const auto &rv = r.empty() ? r.e : r.get();
    return f(lv, rv);
  }
  int size() const { return l.size() + r.size(); }
  bool empty() const { return l.empty() and r.empty(); }
  void pop() { rebalance(); r.pop(); }
  void swap(FQueue &o) { l.swap(o.l), r.swap(o.r); }
};
