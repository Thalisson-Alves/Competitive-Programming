#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

using vi = vector<int>;
using vi2d = vector<vi>;
#define len(__x) (int)__x.size()
#define eb emplace_back
template <typename T>
struct SparseTable {
  vector<T> v;
  int n;
  static const int b = 30;
  vi mask, t;

  int op(int x, int y) { return v[x] < v[y] ? x : y; }
  int msb(int x) { return __builtin_clz(1) - __builtin_clz(x); }
  SparseTable() {}
  SparseTable(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
    for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
      at = (at << 1) & ((1 << b) - 1);
      while (at and op(i, i - msb(at & -at)) == i) at ^= at & -at;
    }
    for (int i = 0; i < n / b; i++)
      t[i] = b * i + b - 1 - msb(mask[b * i + b - 1]);
    for (int j = 1; (1 << j) <= n / b; j++)
      for (int i = 0; i + (1 << j) <= n / b; i++)
        t[n / b * j + i] =
          op(t[n / b * (j - 1) + i], t[n / b * (j - 1) + i + (1 << (j - 1))]);
  }
  int small(int r, int sz = b) { return r - msb(mask[r] & ((1 << sz) - 1)); }
  T query(int l, int r) {
    if (r - l + 1 <= b) return small(r, r - l + 1);
    int ans = op(small(l + b - 1), small(r));
    int x = l / b + 1, y = r / b - 1;
    if (x <= y) {
      int j = msb(y - x + 1);
      ans = op(ans, op(t[n / b * j + x], t[n / b * j + y - (1 << j) + 1]));
    }
    return ans;
  }
};

struct LCA {
  SparseTable<int> st;
  int n;
  vi v, pos, dep;

  LCA(const vi2d& g, int root) : n(len(g)), pos(n) {
    dfs(root, 0, -1, g);
    st = SparseTable<int>(vector<int>(all(dep)));
  }

  void dfs(int i, int d, int p, const vi2d& g) {
    v.eb(len(dep)) = i, pos[i] = len(dep), dep.eb(d);
    for (auto j : g[i])
      if (j != p) {
        dfs(j, d + 1, i, g);
        v.eb(len(dep)) = i, dep.eb(d);
      }
  }

  int lca(int a, int b) {
    int l = min(pos[a], pos[b]);
    int r = max(pos[a], pos[b]);
    return v[st.query(l, r)];
  }
  int dist(int a, int b) {
    return dep[pos[a]] + dep[pos[b]] - 2 * dep[pos[lca(a, b)]];
  }
};

void dfs(const vector<vector<int>> &g, int u, int p, vector<int> &ps, vector<vector<int>> &sum, vector<vector<int>> &closest, vector<int> closest_acc, const vector<ll> &a) {
  if (p != -1) {
    for (int i = 0; i < (int)sum[u].size(); i++) {
      sum[u][i] += sum[p][i];
    }
  }
  for (int i = 0; i < (int)sum[u].size(); i++) {
    if (a[u] & (1ll << i)) {
      sum[u][i]++;
      closest_acc[i] = u;
    }
    closest[u][i] = closest_acc[i];
  }
 
  ps[u] = p;
 
  for (auto x : g[u]) if (x != p) {
    dfs(g, x, u, ps, sum, closest, closest_acc, a);
  }
}
 
void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
 
  LCA lca(g, 0);
 
  ll bits_cnt = (int)log2(*max_element(all(a))) + 1;
  vector<vector<int>> bits(n, vector<int>(bits_cnt)), closest(n, vector<int>(bits_cnt));
  vector<int> closest_acc(bits_cnt, -1), ps(n, -1);
  dfs(g, 0, -1, ps, bits, closest, closest_acc, a);
 
  auto niceness = [&](int x, int u, int v) -> ll {
    if (lca.lca(x, u) != x) swap(u, v);
    int p = lca.lca(u, v);
 
    ll left = 0, right = 0;
    for (int i = 0; i < bits_cnt; i++) {
      if (bits[u][i] - (ps[x] == -1 ? 0 : bits[ps[x]][i]))
        left++;
      if (bits[v][i] + bits[x][i] - 2 * (ps[p] == -1 ? 0 : bits[ps[p]][i]))
        right++;
    }
 
    return left + right;
  };
 
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
 
    ll best_value = niceness(u, u, v);
    auto p = lca.lca(u, v);
    for (int i = 0; i < bits_cnt; i++) {
      if (closest[u][i] != -1 and lca.lca(closest[u][i], p) == p) {
        auto value = niceness(closest[u][i], u, v);
        if (value > best_value) {
          best_value = value;
        }
      }
      if (closest[v][i] != -1 and lca.lca(closest[v][i], p) == p) {
        auto value = niceness(closest[v][i], u, v);
        if (value > best_value) {
          best_value = value;
        }
      }
    }
 
    cout << best_value << ' ';
  }
  cout << '\n';
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}

