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

template <typename T>
struct MergeSortTree {
  int N;
  vector<vector<T>> v;

  MergeSortTree(const vector<T> &a) : N((int)a.size()), v(4 * N) {
    build(a, 1, 0, N-1);
  }

  int query(int l, int r, T mn, T mx) const {
    return query(1, 0, N-1, l, r, mn, mx);
  }
private:
  void build(const vector<T> &a, int node, int tl, int tr) {
    if (tl == tr) {
      v[node] = {a[tl]};
    } else {
      auto tm = tl + (tr - tl) / 2;
      build(a, 2*node, tl, tm);
      build(a, 2*node+1, tm+1, tr);
      merge(all(v[2*node]), all(v[2*node+1]), back_inserter(v[node]));
    }
  }

  int query(int node, int tl, int tr, int l, int r, T mn, T mx) const {
    if (r < tl or tr < l) return T();
    if (l <= tl and tr <= r) {
      return (int)(lower_bound(all(v[node]), mx) - lower_bound(all(v[node]), mn));
    }

    auto tm = tl + (tr - tl) / 2;
    return query(2*node, tl, tm, l, r, mn, mx) + query(2*node+1, tm+1, tr, l, r, mn, mx);
  }
};

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> per(n);
  for (auto &x : per) cin >> x, --x;

  vector<int> tin(n), tout(n);
  {
    int timer = 0;
    y_combinator([&](auto &&dfs, int u, int p=-1) -> void {
      tin[u] = timer++;
      for (auto v : g[u]) if (v != p) {
        dfs(v, u);
      }
      tout[u] = timer++;
    })(0);
  }

  vector<int> a(n);
  for (int i = 0; i < n; i++) a[i] = tin[per[i]];
  MergeSortTree mst(a);
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    --l, --r, --x;
    cout << (mst.query(l, r, tin[x], tout[x]) ? "YES" : "NO") << '\n';
  }
  cout << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
