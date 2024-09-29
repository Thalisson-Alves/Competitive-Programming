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

template <const int mod>
int tree_hash(const vector<vector<int>> &g, int u, int p, const vector<int> &sz, const vector<ll> &powers) {
  priority_queue<pair<int, int>> pq;
  for (auto x : g[u])
    if (x != p)
    pq.emplace(tree_hash<mod>(g, x, u, sz, powers), sz[x]);

  ll value = 1;
  for (; not pq.empty(); pq.pop()) {
    auto [x, y] = pq.top();
    value = (value * powers[y+1] % mod + x) % mod;
  }
  return (int)(value << 1) % mod;
}

template <const int mod = static_cast<int>(1e9 + 9)>
int tree_hash(const vector<vector<int>> &g, int root, const vector<int> &sz) {
  vector<ll> powers(g.size() + 1);
  powers[0] = 1;
  for (int i = 1; i < (int)powers.size(); i++)
    powers[i] = (powers[i-1] << 1) % mod;

  return tree_hash<mod>(g, root, -1, sz, powers);
}

template <const int mod = static_cast<int>(1e9 + 9)>
int tree_hash(const vector<vector<int>> &g, int root) {
  auto dfs = [](auto &&self, const vector<vector<int>> &adj, int u, int p, vector<int> &sz) -> void {
    sz[u] = 1;
    for (auto x : adj[u]) if (x != p) {
      self(self, adj, x, u, sz);
      sz[u] += sz[x];
    }
  };

  vector<int> sz(g.size());
  dfs(dfs, g, root, -1, sz);

  return tree_hash<mod>(g, root, sz);
}

template <const int mod = static_cast<int>(1e9 + 9)>
int tree_hash(const vector<vector<int>> &g) {
  int root = -1;
  auto dfs = [&root](auto &&self, const vector<vector<int>> &adj, int u, int p, vector<int> &sz) -> void {
    sz[u] = 1;
    bool is_centroid = true;
    for (auto x : adj[u]) if (x != p) {
      self(self, adj, x, u, sz);
      sz[u] += sz[x];
      is_centroid &= sz[x] <= (int)adj.size() >> 1;
    }
    if (is_centroid) root = u;
  };

  vector<int> sz(g.size());
  dfs(dfs, g, 0, -1, sz);
  return tree_hash(g, root, sz);
}

template <const int mod = static_cast<int>(1e9 + 9)>
bool is_isomorphic(const vector<vector<int>> &a, int ra, const vector<vector<int>> &b, int rb) {
  return tree_hash<mod>(a, ra) == tree_hash<mod>(b, rb);
}

template <const int mod = static_cast<int>(1e9 + 9)>
bool is_isomorphic(const vector<vector<int>> &a, const vector<vector<int>> &b) {
  return tree_hash<mod>(a) == tree_hash<mod>(b);
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> a(n), b(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    b[u].push_back(v);
    b[v].push_back(u);
  }

  cout << (is_isomorphic(a, 0, b, 0) ? "YES" : "NO") << '\n';
}

int32_t main() {
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
