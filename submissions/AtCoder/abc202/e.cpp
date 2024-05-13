#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

vector<pair<int, int>> tree_flatten(const vector<vector<int>> &g, int root = 0) {
  vector<int> pre;
  pre.reserve(g.size());
  vector<pair<int, int>> flat(g.size());
  int timer = -1;
  auto dfs = [&](auto &&self, int u, int p) -> void {
    ++timer;
    pre.push_back(u);
    for (auto v : g[u]) if (v != p) {
      self(self, v, u);
    }
    flat[u].second = timer;
  };
  dfs(dfs, root, -1);
  for (int i = 0; i < (int)g.size(); i++)
    flat[pre[i]].first = i;
  return flat;
}

template <typename T> struct WaveletTree {
  struct Node {
    T lo, hi;
    int left_child, right_child;
    vector<int> b;

    Node(int lo_, int hi_) : lo(lo_), hi(hi_), left_child(0), right_child(0), b() {}
  };

  vector<Node> nodes;
  WaveletTree(vector<T> &v) {
    // TODO: maybe make it 2*distinc(v). Don't know if it's worth it tho.
    nodes.reserve(2*v.size());
    auto [mn, mx] = minmax_element(v.begin(), v.end());
    build(nodes[make_node(*mn, *mx)], v.begin(), v.end());
  }

  T kth_element(int l, int r, int k) const {
    return kth_element(nodes[0], l, r, k);
  }
  int count_less(int l, int r, T k) const {
    if (l > r) return 0;
    constexpr auto base = [](const Node & node, T x) -> int {
      if (node.lo >= x) return 0;
      if (node.hi < x) return 1;
      return -1;
    };
    return count_query<T, base>(nodes[0], l, r, k);
  }
  int count_greater(int l, int r, T k) const {
    constexpr auto base = [](const Node & node, T x) -> int {
      if (node.hi <= x) return 0;
      if (node.lo > x) return 1;
      return -1;
    };
    return count_query<T, base>(nodes[0], l, r, k);
  }
  int count_equal(int l, int r, T k) const {
    constexpr auto base = [](const Node & node, T x) -> int {
      if (node.lo > x) return 0;
      if (node.hi < x) return 0;
      if (node.lo == node.hi) return (x == node.lo);
      return -1;
    };
    return count_query<T, base>(nodes[0], l, r, k);
  }
  int count_in_range(int l, int r, T a, T b) const {
    constexpr auto base = [](const Node &node, const pair<T, T> &x) -> int {
      if (node.lo > x.second or node.hi < x.first) return 0;
      if (x.first <= node.lo and node.hi <= x.second) return 1;
      return -1;
    };
    return count_query<pair<T, T>, base>(nodes[0], l, r, pair<T, T>(a, b));
  }
private:
  void build(Node &node, typename vector<T>::iterator from, typename vector<T>::iterator to) {
    if (node.lo == node.hi or from >= to) return;
    auto mid = midpoint(node.lo, node.hi);
    auto f = [&mid](T x) { return x <= mid; };
    node.b.reserve(to - from + 1);
    node.b.push_back(0);
    T left_upper = node.lo, right_lower = node.hi;
    for (auto it = from; it != to; it++) {
      auto value = f(*it);
      node.b.push_back(node.b.back() + value);
      if (value) left_upper = max(left_upper, *it);
      else right_lower = min(right_lower, *it);
    }

    auto pivot = stable_partition(from, to, f);
    node.left_child = make_node(node.lo, left_upper);
    build(nodes[node.left_child], from, pivot);
    node.right_child = make_node(right_lower, node.hi);
    build(nodes[node.right_child], pivot, to);
  }

  template <typename K, auto handle_base>
  int count_query(const Node &node, int l, int r, K k) const {
    static_assert(is_invocable_r_v<int, decltype(handle_base), Node, K>);

    if (l > r) return 0;
    {
      auto b = handle_base(node, k);
      if (~b) return b * (r - l + 1);
    }
    int lb = node.b[l], rb = node.b[r+1];
    return count_query<K, handle_base>(nodes[node.left_child], lb, rb-1, k) + count_query<K, handle_base>(nodes[node.right_child], l-lb, r-rb, k);
  }

  T kth_element(const Node &node, int l, int r, int k) const {
    if (l > r) return 0;
    if (node.lo == node.hi) return node.lo;
    int lb = node.b[l], rb = node.b[r+1], left_size = rb - lb;
    return (left_size > k ? kth_element(nodes[node.left_child], lb, rb-1, k) : kth_element(nodes[node.right_child], l-lb, r-rb, k-left_size));
  }

  int make_node(T lo, T hi) {
    int id = (int)nodes.size();
    nodes.emplace_back(lo, hi);
    return id;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    --x;
    g[i].push_back(x);
    g[x].push_back(i);
  }

  auto flat = tree_flatten(g);
  vector<int> depth(n);
  {
    auto dfs = [&](auto &&self, int u, int p) -> void {
      for (auto v : g[u]) if (v != p) {
        depth[flat[v].first] = depth[flat[u].first] + 1;
        self(self, v, u);
      }
    };
    dfs(dfs, 0, -1);
  }
  WaveletTree wt(depth);
  int q;
  cin >> q;
  while (q--) {
    int u, d;
    cin >> u >> d;
    --u;
    cout << wt.count_equal(flat[u].first, flat[u].second, d) << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
