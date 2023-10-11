#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void tree_flatten(const vector<vector<int>> &g, int u, int p, vector<int> &pre, vector<int> &pos, int &idx) {
  ++idx;
  pre.push_back(u);
  for (auto x : g[u])
    if (x != p)
      tree_flatten(g, x, u, pre, pos, idx);
  pos[u] = idx;
}

vector<pair<int,int>> tree_flatten(const vector<vector<int>> &g, int root=0) {
  vector<int> last(g.size()), pre;
  int timer = -1;
  tree_flatten(g, root, -1, pre, last, timer);

  vector<pair<int, int>> res(g.size());
  for (int i = 0; i < (int)g.size(); i++)
    res[pre[i]] = {i, last[i]};
  return res;
}

template <typename T> struct SegTree {
  int N;
  vector<T> v, lazy;
 
  SegTree(int n) : N(n), v(4 * N), lazy(4 * N) {}
  SegTree(const vector<T> &xs) : N((int)xs.size()), v(4 * N), lazy(4 * N, 0) {
    for (int i = 0; i < N; i++)
      update(i, xs[i]);
  }
 
  void update(int i, T value) { update(i, i, value); }
  void update(int a, int b, T value) { update(1, 0, N - 1, a, b, value); }
  T query(int a, int b) { return query(1, 0, N - 1, a, b); }
  T query(int a) { return query(1, 0, N - 1, a, a); }
 
private:
  void apply_propagation(int node, int l, int r) {
    v[node] += (r - l + 1) * lazy[node];
    propagate(node, l, r, lazy[node]);
    lazy[node] = 0;
  }
 
  void propagate(int node, int l, int r, T value) {
    if (l >= r)
      return;
 
    lazy[2 * node] += value;
    lazy[2 * node + 1] += value;
  }
 
  void update(int node, int l, int r, int a, int b, T value) {
    if (lazy[node])
      apply_propagation(node, l, r);
 
    if (a > r or b < l)
      return;
 
    if (a <= l and b >= r) {
      v[node] += (r - l + 1) * value;
      propagate(node, l, r, value);
      return;
    }
 
    auto m = l + (r - l) / 2;
    update(2 * node, l, m, a, b, value);
    update(2 * node + 1, m + 1, r, a, b, value);
 
    v[node] = v[2 * node] + v[2 * node + 1];
  }
 
  T query(int node, int l, int r, int a, int b) {
    if (lazy[node])
      apply_propagation(node, l, r);
 
    if (a > r or b < l)
      return 0;
 
    if (a <= l and b >= r)
      return v[node];
 
    auto m = l + (r - l) / 2;
    auto x = query(2 * node, l, m, a, b);
    auto y = query(2 * node + 1, m + 1, r, a, b);
    return x + y;
  }
};

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<ll> vs(n);
  for (auto &x : vs) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  auto rng = tree_flatten(g);
  SegTree<ll> st(n);
  for (int i = 0; i < n; i++) {
    st.update(rng[i].first, rng[i].second, vs[i]);
    dbg(i, rng[i], vs[i], st.query(rng[i].first));
  }

  while (q--) {
    int t, u;
    cin >> t >> u;
    --u;
    if (t == 1) {
      int v;
      cin >> v;
      st.update(rng[u].first, rng[u].second, v-vs[u]);
      vs[u] = v;
    } else {
      cout << st.query(rng[u].first) << '\n';
    }
  }
  cout << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}
