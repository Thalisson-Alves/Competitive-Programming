template <typename T, typename Q=T, typename F=function<Q(Q,T)>>
struct FStack {
  F f; Q e;
  stack<pair<T, Q>> st;
  FStack(F op = F(), Q id = Q()) : f(op), e(id) {}
  void push(T x) {
    Q acc = (!st.empty() ? get() : e);
    st.emplace(x, f(acc, x));
  }
  const T &top() const { return st.top().first; }
  const Q &get() const { return st.top().second; }
  void pop() { st.pop(); }
  int size() const { return (int)st.size(); }
  bool empty() const { return st.empty(); }
  void swap(FStack &o) { st.swap(o.st), f.swap(o.f), e.swap(o.e); }
};
