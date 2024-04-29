#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, char>>> g(n);
  vector<unordered_set<int>> nei(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    --u, --v;
    g[u].emplace_back(v, c);
    g[v].emplace_back(u, c);
    nei[u].insert(v);
    nei[v].insert(u);
  }

  queue<pair<int, int>> q({{0, n-1}});
  map<pair<int, int>, int> dist;
  uint res = UINT_MAX;
  while (not q.empty()) {
    auto [a, b] = q.front();
    auto d = dist[q.front()];
    if ((uint)d << 1 >= res) break;
    q.pop();

    if (nei[a].count(b)) res = min(res, (uint)d << 1 | 1);
    if (a == b) res = min(res, (uint)d << 1);

    unordered_map<char, vector<int>> mp;
    for (auto [u, c] : g[a]) mp[c].push_back(u);
    for (auto [v, c] : g[b]) {
      for (auto u : mp[c]) {
        if (!dist.count({u, v})) {
          dist[{u, v}] = d+1;
          q.emplace(u, v);
        }
      }
    }
  }

  cout << (int)res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
