#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

// O((n+m)*log(n))
struct BridgeFinder {
  // 2ecc = 2 edge conected component
  // cc = conected component
  vector<int> parent, dsu_2ecc, dsu_cc, dsu_cc_size;
  int bridges_cnt, lca_iteration;
  vector<int> last_visit;

  BridgeFinder(int n) : parent(n, -1), dsu_2ecc(n), dsu_cc(n), dsu_cc_size(n, 1), bridges_cnt(0), lca_iteration(0), last_visit(n) {
    for (int i = 0; i < n; i++) {
      dsu_2ecc[i] = i;
      dsu_cc[i] = i;
    }
  }

  int find_2ecc(int v) {
    if (v == -1) return -1;
    return dsu_2ecc[v] == v ? v : dsu_2ecc[v] = find_2ecc(dsu_2ecc[v]);
  }

  int find_cc(int v) {
    v = find_2ecc(v);
    return dsu_cc[v] == v ? v : dsu_cc[v] = find_cc(dsu_cc[v]);
  }

  void make_root(int v) {
    v = find_2ecc(v);
    int root = v;
    int child = -1;
    while (v != -1) {
      int p = find_2ecc(parent[v]);
      parent[v] = child;
      dsu_cc[v] = root;
      child = v;
      v = p;
    }
    dsu_cc_size[root] = dsu_cc_size[child];
  }

  void merge_path(int a, int b) {
    ++lca_iteration;
    vector<int> path_a, path_b;
    int lca = -1;
    while (lca == -1) {
      if (a != -1) {
        a = find_2ecc(a);
        path_a.push_back(a);
        if (last_visit[a] == lca_iteration){
          lca = a;
          break;
        }
        last_visit[a] = lca_iteration;
        a = parent[a];
      }
      if (b != -1) {
        b = find_2ecc(b);
        path_b.push_back(b);
        if (last_visit[b] == lca_iteration) {
          lca = b;
          break;
        }
        last_visit[b] = lca_iteration;
        b = parent[b];
      }
    }

    for (auto v : path_a) {
      dsu_2ecc[v] = lca;
      if (v == lca) break;
      --bridges_cnt;
    }
    for (auto v : path_b) {
      dsu_2ecc[v] = lca;
      if (v == lca) break;
      --bridges_cnt;
    }
  }

  void add_edge(int a, int b) {
    a = find_2ecc(a);
    b = find_2ecc(b);

    if (a == b) return;

    int ca = find_cc(a);
    int cb = find_cc(b);

    if (ca != cb) {
      ++bridges_cnt;
      if (dsu_cc_size[ca] > dsu_cc_size[cb]) {
        swap(a, b);
        swap(ca, cb);
      }
      make_root(a);
      parent[a] = dsu_cc[a] = b;
      dsu_cc_size[cb] += dsu_cc_size[a];
    } else {
      merge_path(a, b);
    }
  }

  inline bool is_bridge(int u, int v) { return find_2ecc(u) != find_2ecc(v); }
};

void solve() {
  int n, m;
  cin >> n >> m;
  BridgeFinder bf(n);
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edges[i] = {u, v};
    bf.add_edge(u, v);
  }

  vector<pair<int, int>> res;
  for (auto [u, v] : edges) {
    if (bf.is_bridge(u, v)) {
      res.emplace_back(u+1, v+1);
    }
  }

  cout << res.size() << '\n';
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i].first << ' ' << res[i].second << '\n';
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
