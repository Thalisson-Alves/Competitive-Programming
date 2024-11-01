#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
  T front() { if (l.empty()) rebalance(); return l.top(); }
  T back() { if (r.empty()) rebalance(); return r.top(); }
  void swap(FDeque &o) { l.swap(o.l), r.swap(o.r); }
};

void solve() {
  int q; cin >> q;
  struct Edge {
    int type, to, value1, value2;
  };
  vector<vector<Edge>> g(q+1);
  vector<vector<pair<int, int>>> qs(q+1);
  vector<int> res;
  {
    int time = 0;
    vector<int> ids(q+1);
    int sz = 1, query = 0;
    while (q--) {
      int t, x;
      cin >> t >> x;
      --x;
      if (t == 1) {
        g[ids[x]].emplace_back(t, ids[sz++] = ++time);
      } else if (t == 2) {
        int p, v;
        cin >> p >> v;
        g[ids[x]].emplace_back(t, ++time, p, v);
        ids[x] = time;
      } else if (t == 3) {
        g[ids[x]].emplace_back(t, ++time);
        ids[x] = time;
      } else {
        int p;
        cin >> p;
        qs[ids[x]].emplace_back(query++, p);
      }
    }
    res.resize(query);
  }
  constexpr int m = 2000;
  using dp_t = array<int, m+1>;
  constexpr auto f = [](dp_t dp, const pair<int, int> &x) {
    for (int i = m; i >= x.first; --i)
      dp[i] = max(dp[i], dp[i-x.first] + x.second);
    return dp;
  };
  FDeque<pair<int, int>, dp_t> dq(f, {0});
  auto dfs = [&](auto &&self, int u) -> void {
    for (auto [id, p] : qs[u]) {
      dq.get([&](const auto &l, const auto &r) {
        for (int i = 0; i <= p; i++)
          res[id] = max(res[id], l[i] + r[p-i]);
      });
    }
    for (auto [t, v, p, x] : g[u]) {
      if (t == 1) {
        self(self, v);
      } else if (t == 2) {
        dq.push_back({p, x});
        self(self, v);
        dq.pop_back();
      } else {
        auto fr = dq.front();
        dq.pop_front();
        self(self, v);
        dq.push_front(fr);
      }
    }
  };
  dfs(dfs, 0);
  for (auto x : res) cout << x << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
