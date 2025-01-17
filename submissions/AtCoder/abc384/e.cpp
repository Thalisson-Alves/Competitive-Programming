#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll n, m, k, p, q;
  cin >> n >> m >> k >> p >> q;
  --p, --q;
  vector<vector<ll>> g(n, vector<ll>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  using T = tuple<ll, ll, ll>;
  priority_queue<T, vector<T>, greater<>> pq;
  constexpr int dir4[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<vector<char>> vis(n, vector<char>(m));
  for (auto [dx, dy] : dir4) {
    ll x = dx + p;
    ll y = dy + q;
    if (0 <= x and x < n and 0 <= y and y < m) {
      pq.emplace(g[x][y], x, y);
      vis[x][y] = 1;
    }
  }
  vis[p][q] = 1;
  while (pq.size()) {
    auto [c, i, j] = pq.top();
    pq.pop();
    if (c >= LLONG_MAX/k) break;
    if (c*k >= g[p][q]) break;
    g[p][q] += c;
    for (auto [dx, dy] : dir4) {
      ll x = dx + i;
      ll y = dy + j;
      if (0 <= x and x < n and 0 <= y and y < m and !vis[x][y]) {
        pq.emplace(g[x][y], x, y);
        vis[x][y] = 1;
      }
    }
  }
  cout << g[p][q] << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
