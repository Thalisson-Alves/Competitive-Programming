#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T, typename Op> struct SparseTable {
  vector<vector<T>> st;
  Op f;
  const T id;
  // Lazy loading constructor. Needs to call build!
  SparseTable(Op op, const T neutral = T()) : st(), f(op), id(neutral) {}
  SparseTable(const vector<T> &v, Op op = Op(), const T neutral = T()) : st(), f(op), id(neutral) { build(v); }
  void build(const vector<T> &v) {
    auto logn = 31-__builtin_clz((int)size(v));
    st.resize(logn+1, vector<T>(v.size()));
    st[0] = v;
    for (int i = 1; i <= logn; i++)
      for (int j = 0; j + (1 << i) <= (int)v.size(); j++)
        st[i][j] = f(st[i-1][j], st[i-1][j+(1 << (i-1))]);
  }
  T query(int l, int r) const {
    assert(l <= r);
    auto lg = 31-__builtin_clz(r-l+1);
    return f(st[lg][l], st[lg][r-(1<<lg)+1]);
  }
  // Non RMQ query
  T query_complete(int l, int r) const {
    assert(l <= r);
    T acc = id;
    for (int i = 31-__builtin_clz(size(st[0])); ~i; --i)
      if ((1 << i) <= r - l + 1) {
        acc = f(acc, st[i][l]);
        l += 1 << i;
      }
    return acc;
  }
};

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;
  vector<ll> pref(n+1);
  partial_sum(begin(v), end(v), begin(pref)+1);
  auto op = [](auto x, auto y) { return min(x, y); };
  SparseTable<ll, decltype(op)> st(pref, op, LLONG_MAX);
  ll res = LLONG_MIN;
  for (int i = a; i <= n; i++)
    res = max(res, pref[i]-st.query(max(i-b,0), i-a));
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
