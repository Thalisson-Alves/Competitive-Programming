#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

struct BinaryLifting {
  vector<int> far, level, parent;

  BinaryLifting(const vector<vector<int>> &g, int root=0) : far(g.size(), -1), level(g.size()), parent(g.size(), -1) {
    level[root] = 1;
    vector<int> q{root};
    q.reserve(g.size());
    for (int i = 0; i < (int)q.size(); i++) {
      auto u = q[i];
      for (auto x : g[u]) if (x != parent[u]) {
        parent[x] = u;
        level[x] = level[u] + 1;

        int p1 = u;
        int p2 = far[u];

        if (p2 > -1 and far[p2] > -1 and level[p1] - level[p2] == level[p2] - level[far[p2]])
          far[x] = far[p2];
        else
          far[x] = p1;

        q.push_back(x);
      }
    }
  }

  int kth_parent(int node, int k) const
  {
    while (node >= 0 and k > 0)
    {
      if (far[node] > -1 and level[node] - k <= level[far[node]])
      {
        k -= level[node] - level[far[node]];
        node = far[node];
      }
      else
      {
        k--;
        node = parent[node];
      }
    }

    return node;
  }

  int lca(int u, int v) const {
    if (level[u] < level[v]) swap(u, v);

    while (level[v] < level[u]) {
      if (far[u] > -1 and level[v] <= level[far[u]])
        u = far[u];
      else
        u = parent[u];
    }

    if (u == v) return u;

    while (parent[u] != parent[v]) {
      if (far[u] > -1 and far[v] > -1 and far[u] != far[v]) {
        u = far[u];
        v = far[v];
      } else {
        u = parent[u];
        v = parent[v];
      }
    }

    return parent[u];
  }
};

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T, auto op>
struct SegTree {
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

  T query_all() const {
    return ns[1];
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

/*
Used to define recursive lambdas,  first argument is the function itself

auto value = y_combinator([](auto &&gcd, int a, int b) -> int {
  return b ? gcd(b, a % b) : a;
});
*/
template <class Fun> class y_combinator_result {
  Fun fun_;

  public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  vector<int> ages(n);
  for (int i = 0; i < n; i++) {
    int p;
    cin >> ages[i] >> p;
    --p;
    if (i) g[p].push_back(i);
  }

  BinaryLifting bl(g);
  auto find_owner = [&bl, &ages](int u, int r) -> int {
    while (bl.parent[u] != -1 and ages[bl.parent[u]] <= r) {
      if (bl.far[u] != -1 and ages[bl.far[u]] <= r)
        u = bl.far[u];
      else
        u = bl.parent[u];
    }
    return u;
  };
  vector<vector<int>> queries(n);
  while (q--) {
    int o, l, r;
    cin >> o >> l >> r;
    queries[find_owner(o-1, r)].push_back(l);
  }

  SegTree<int, F(a+b)> seg(1e5+1);
  vector<int> ans(n);
  y_combinator([&](auto &&dfs, int u) -> void {
    for (auto x : queries[u])
      seg.update(x, 1);

    ans[u] += seg.query(0, ages[u]);

    for (auto v : g[u])
      dfs(v);

    for (auto x : queries[u])
      seg.update(x, -1);
  })(0);

  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n-1];
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
