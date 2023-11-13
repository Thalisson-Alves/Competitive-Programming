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

// O(n + m)
struct BlockCutTree {
  vector<vector<int>> blocks, tree;
  vector<vector<pair<int, int>>> block_edges;
  vector<int> articulation, pos;

  BlockCutTree(const vector<vector<int>> &g) : articulation(g.size()), pos(g.size()) {
    int t = 0;
    vector<int> id(g.size(), -1);
    stack<int> s1;
    stack<pair<int, int>> s2;
    for (int i = 0; i < (int)g.size(); i++)
      if (id[i] == -1)
        dfs(g, i, -1, t, id, s1, s2);

    tree.resize(blocks.size());
    for (int i = 0; i < (int)g.size(); i++)
      if (articulation[i])
        pos[i] = (int)tree.size(), tree.emplace_back();

    for (int i = 0; i < (int)blocks.size(); i++) {
      for (auto j : blocks[i]) {
        if (not articulation[j]) pos[j] = i;
        else tree[i].push_back(pos[j]), tree[pos[j]].push_back(i);
      }
    }
  }

private:
  int dfs(const vector<vector<int>> &g, int i, int p, int &t, vector<int> &id, stack<int> &s1, stack<pair<int, int>> &s2) {
    int lo = id[i] = t++;
    s1.push(i);

    if (p != -1) s2.emplace(i, p);
    for (auto j : g[i])
      if (j != p and id[j] != -1)
        s2.emplace(i, j);

    for (auto j : g[i]) if (j != p) {
      if (id[j] == -1) {
        int val = dfs(g, j, i, t, id, s1, s2);
        lo = min(lo, val);

        if (val >= id[i]) {
          articulation[i]++;
          blocks.emplace_back(1, i);
          for (; blocks.back().back() != j; s1.pop())
            blocks.back().push_back(s1.top());

          block_edges.emplace_back(1, s2.top());
          s2.pop();
          for (; block_edges.back().back() != make_pair(j, i); s2.pop())
            block_edges.back().push_back(s2.top());
        }
      } else {
        lo = min(lo, id[j]);
      }
    }

    if (p == -1 and articulation[i]) --articulation[i];
    return lo;
  }
};

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T> struct SparseTable
{
  using Operation = T(*)(T, T);

  int LOGN;
  vector<vector<T>> st;
  Operation f;
  T identity;

  static constexpr int log2_floor(unsigned long long i) noexcept { return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1; }

  // Lazy loading constructor. Needs to call build!
  SparseTable(Operation op, const T neutral = T()) : LOGN(), st(), f(op), identity(neutral) {}

  SparseTable(const vector<T> &v) : SparseTable(v, F(max(a,b))) { }

  SparseTable(const vector<T> &v, Operation op, const T neutral = T()) : LOGN(), st(), f(op), identity(neutral)
  {
    build(v);
  }

  void build(const vector<T> &v)
  {
    LOGN = log2_floor(v.size());
    st.resize(LOGN+1, vector<T>(v.size()));

    st[0] = v;
    for (int i = 1; i <= LOGN; i++)
      for (int j = 0; j + (1 << i) <= (int)v.size(); j++)
        st[i][j] = f(st[i-1][j], st[i-1][j+(1 << (i-1))]);
  }

  // Non RMQ query
  T query_complete(int l, int r) const
  {
    T acc = identity;
    for (int i = LOGN; ~i; --i)
      if ((1 << i) <= r - l + 1)
      {
        acc = f(acc, st[i][l]);
        l += 1 << i;
      }
    return acc;
  }

  T query(int l, int r) const
  {
    auto lg = log2_floor(r-l+1);
    return f(st[lg][l], st[lg][r - (1 << lg) + 1]);
  }
};

struct LCA {
  vector<int> height, euler, first;
  SparseTable<pair<int, int>> table;

  LCA(vector<vector<int>> &g, int root = 0) : height(g.size()), euler(g.size() * 2), first(g.size()), table(F(min(a,b)),{INT_MAX,INT_MAX}) {
    vector<bool> visited(g.size());
    dfs(g, root, visited);
    int m = (int)euler.size();
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++) v[i] = {height[euler[i]], euler[i]};
    table.build(v);
  }

  void dfs(vector<vector<int>> &adj, int node, vector<bool> &visited, int h = 0) {
    visited[node] = true;
    height[node] = h;
    first[node] = (int)euler.size();
    euler.push_back(node);
    for (auto to : adj[node]) {
      if (!visited[to]) {
        dfs(adj, to, visited, h + 1);
        euler.push_back(node);
      }
    }
  }

  int lca(int u, int v) {
    int left = first[u], right = first[v];
    if (left > right) swap(left, right);
    auto x = table.query(left, right);
    return x.second;
  }
};

void solve()
{
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  BlockCutTree ct(g);

  LCA lca(ct.tree);
  vector<ll> d(ct.tree.size());
  y_combinator([&ct, &d](auto &&dfs, int u, int p) -> void {
    for (auto x : ct.tree[u]) if (x != p) {
      d[x] = d[u] + 1;
      dfs(x, u);
    }
  })(0, 0);
  auto dist = [&lca, &d, &ct](int u, int v) {
    u = ct.pos[u];
    v = ct.pos[v];
    auto l = lca.lca(u, v);
    return d[u] + d[v] - 2*d[l];
  };

  while (q--) {
    int u, v, c;
    cin >> u >> v >> c;
    --u, --v, --c;
    if (u == c or v == c) {
      cout << "NO\n";
    } else if (!ct.articulation[c]) {
      cout << "YES\n";
    } else {
      cout << (dist(u,c)+dist(c,v)==dist(u,v) ? "NO" : "YES") << '\n';
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
