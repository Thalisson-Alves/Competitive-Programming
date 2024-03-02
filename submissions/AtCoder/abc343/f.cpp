#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

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

struct Node {
  int big = -1, bcnt = 0;
  int small = -2, scnt = 0;
};

Node op(const Node &a, const Node &b) {
  if (a.big == -1) return b;
  if (b.big == -1) return a;
  map<int, int> mp;
  mp[a.big] += a.bcnt;
  mp[a.small] += a.scnt;
  mp[b.big] += b.bcnt;
  mp[b.small] += b.scnt;
  auto it = mp.rbegin();
  return Node(it->first, it->second, next(it)->first, next(it)->second);
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for (auto &x : v) cin >> x;

  SegTree<Node, op> seg(n);
  for (int i = 0; i < n; i++) seg.set(i, Node(v[i], 1));

  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      --a;
      seg.set(a, Node(b, 1));
      v[a] = b;
    } else {
      --a, --b;
      auto res = seg.query(a, b);
      if (res.small < 0) {
        cout << "0\n";
      } else {
        cout << res.scnt << '\n';
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
