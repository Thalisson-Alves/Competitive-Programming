#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T, auto op> struct SegTree {
  static_assert(std::is_convertible_v<decltype(op), std::function<T(T, T)>>,
                "Operation must be convertible to std::function<T(T, T)>");

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
    l = l + N;
    r = r + N;

    auto ml = identity, mr = identity;
    while (l <= r) {
      if (l & 1) ml = op(ml, ns[l++]);
      if (not (r & 1)) mr = op(ns[r--], mr);

      l >>= 1;
      r >>= 1;
    }

    return op(ml, mr);
  }

  void update(size_t i, T value) {
    set(i, op(ns[i + N], value));
  }

  void set(size_t i, T value) {
    auto a = i + N;

    ns[a] = value;
    while (a >>= 1)
      ns[a] = op(ns[2 * a], ns[2 * a + 1]);
  }
};

struct Node {
  ll hash;
  int size;

  Node() : hash(0), size(0) {}
  Node(ll h, int s) : hash(h), size(s) {}
};

vector<ll> power;
constexpr ll MOD = 1e9+7;

Node op(const Node &a, const Node &b) {
  return {(a.hash + (b.hash * power[a.size]) % MOD) % MOD, a.size + b.size};
}

void solve()
{
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  constexpr ll pot = 31, mod = 1e9+7;
  power.resize(n+1);
  power[0] = 1;
  for (int i = 0; i < n; i++) {
    power[i+1] = power[i] * pot % mod;
  }

  SegTree<Node, op> seg(n+1), rev(n+1);
  for (int i = 0; i < n; i++) {
    seg.set(i, {s[i]-'a'+1, 1});
    rev.set(i, {s[n-i-1]-'a'+1, 1});
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      char c;
      cin >> x >> c;
      seg.set(x-1, {c-'a'+1, 1});
      rev.set(n-x, {c-'a'+1, 1});
    } else {
      int l, r;
      cin >> l >> r;
      cout << (seg.query(l-1, r-1).hash == rev.query(n-r, n-l).hash ? "YES" : "NO") << '\n';
    }
  }
}

int32_t main()
{
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
