#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T, auto op> struct SegTree {
  static_assert(std::is_invocable_r_v<T, decltype(op), T, T>);

  int N;
  const T identity = T();
  vector<T> ns;

  SegTree(int n, const T identity_ = T()) : N(n), identity(identity_), ns(2 * N, identity)  {}

  SegTree(const vector<T> &v) : SegTree((int)v.size()) {
    copy(v.begin(), v.end(), ns.begin() + N);
    for (int i = N - 1; i > 0; --i)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }

  T query(size_t i) const {
    return ns[i + N];
  }

  T query(size_t l, size_t r) const {
    auto ml = identity, mr = identity;
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ml = op(ml, ns[l++]);
      if (not (r & 1)) mr = op(ns[r--], mr);
    }
    return op(ml, mr);
  }

  void update(size_t i, T value) {
    set(i, op(ns[i + N], value));
  }

  void set(size_t i, T value) {
    ns[i += N] = value;
    while (i >>= 1)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  unordered_map<int, int> mp;
  {
    set<int> st(v.begin(), v.end());
    int id = *st.begin() != 0;
    for (auto x : st)
      mp[x] = id++;
  }

  SegTree<ll, F(a+b)> seg(n+1), cnt(n+1);
  ll res = 0;
  for (auto x : v) {
    auto id = mp[x];
    if (id)
      res += x * cnt.query(0, id-1) - seg.query(0, id-1);
    seg.update(id, x);
    cnt.update(id, 1);
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
