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
template <typename T, auto op>
struct SegTree {
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

void solve()
{
  int n;
  cin >> n;
  vector<array<int, 3>> race(n);
  for (auto &row : race) for (auto &x : row) cin >> x, --x;
  using MaxSeg = SegTree<pair<int, int>, F(max(a, b))>;
  vector<MaxSeg> segs(3, MaxSeg(n, {-1, -1}));
  using MinSeg = SegTree<pair<int, int>, F(min(a, b))>;
  vector<MinSeg> segs_rev(3, MinSeg(n, {n, n}));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      segs[i].set(race[j][i], {race[j][(i+1)%3], j});
      segs_rev[i].set(race[j][i], {race[j][(i+1)%3], j});
    }
  }

  auto order = [&]() {
    vector<int> ord;
    ord.reserve(n);
    vector<bool> vis(n);
    auto dfs = [&](auto &&self, int u) -> void {
      if (vis[u]) return;
      vis[u] = 1;

      for (int i = 0; i < 3; i++)
        segs[i].set(race[u][i], {-1, -1});
      for (int i = 0; i < 3; i++) {
        while (1) {
          auto [p, v] = segs[i].query(race[u][i], n-1);
          if (race[u][(i+1)%3] >= p) break;
          segs[i].set(race[v][i], {-1, v});
          if (!vis[v])
            self(self, v);
        }
      }
      ord.push_back(u);
    };
    for (int i = 0; i < n; i++) {
      if (!vis[i])
        dfs(dfs, i);
    }
    reverse(ord.begin(), ord.end());
    return ord;
  }();

  auto pos = [&]() {
    vector<int> comps(n, -1);
    int id = 0;
    auto dfs = [&](auto &&self, int u) -> void {
      if (~comps[u]) return;
      comps[u] = id;

      for (int i = 0; i < 3; i++)
        segs_rev[i].set(race[u][i], {n, n});
      for (int i = 0; i < 3; i++) {
        while (1) {
          auto [p, v] = segs_rev[i].query(0, race[u][i]);
          if (race[u][(i+1)%3] <= p) break;
          segs_rev[i].set(race[v][i], {n, v});
          if (comps[v] == -1)
            self(self, v);
        }
      }
    };
    for (auto u : order) {
      dfs(dfs, u), id++;
    }
    return comps;
  }();

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << (pos[--u] <= pos[--v] ? "YES" : "NO") << '\n';
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
