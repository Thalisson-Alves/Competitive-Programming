#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T, typename Op = T(*)(T,T)> struct BinaryLifting {
  const int lg;
  vector<vector<int>> up;
  vector<vector<T>> acc;
  vector<int> depth;
  const Op op;
  const T e;
  BinaryLifting(const vector<vector<pair<int, T>>> &g, int root=0, Op f = Op(), T id = T()) : lg(32-__builtin_clz((int)size(g))), up(size(g), vector<int>(lg, root)), acc(size(up), vector<T>(size(up[0]), id)), depth(size(up)), op(f), e(id) {
    vector<int> q{root};
    q.reserve(size(g));
    for (int i = 0; i < (int)q.size(); i++) {
      auto u = q[i];
      for (auto [v, w] : g[u]) if (v != up[u][0]) {
        q.push_back(v);
        up[v][0] = u;
        acc[v][0] = w;
        depth[v] = depth[u] + 1;
        for (int j = 1; j < lg; j++) {
          up[v][j] = up[up[v][j-1]][j-1];
          acc[v][j] = op(acc[v][j-1], acc[up[v][j-1]][j-1]);
        }
      }
    }
  }
  pair<int, T> kth_parent(int u, int k) const {
    T res = e;
    for (int i = lg-1; ~i; --i) {
      if (k>>i&1) {
        res = op(res, acc[u][i]);
        u = up[u][i];
      }
    }
    return {u, res};
  }
  pair<int, T> lca(int u, int v) const {
    if (depth[u] < depth[v]) swap(u, v);
    T res;
    tie(u, res) = kth_parent(u, depth[u]-depth[v]);
    if (u == v) return {u, res};
    for (int i = lg-1; ~i; --i) {
      if (up[u][i] != up[v][i]) {
        res = op(res, op(acc[u][i], acc[v][i]));
        u = up[u][i], v = up[v][i];
      }
    }
    return {up[u][0], op(res, op(acc[u][0], acc[v][0]))};
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  vector<int> fg(n); fg.back() = n;
  for (int i = n-2; ~i; --i) {
    int j = i+1;
    while (j < n and v[j] <= v[i]) j = fg[j];
    fg[i] = j;
  }
  vector<vector<pair<int, int>>> g(n+1);
  for (int i = 0; i < n; i++) g[fg[i]].emplace_back(i, 1);
  BinaryLifting bf(g, n, plus<int>());
  auto f = [&](int u, int r) {
    int res = 0;
    for (int i = bf.lg-1; ~i; --i) {
      if (bf.up[u][i] <= r) {
        res = bf.op(res, bf.acc[u][i]);
        u = bf.up[u][i];
      }
    }
    return res + 1;
  };
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << f(--l, --r) << '\n';
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
