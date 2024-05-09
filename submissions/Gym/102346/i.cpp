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
  vector<int> temp(n);
  for (auto &x : temp) cin >> x;
  vector<vector<ll>> g(n, vector<ll>(n, LLONG_MAX));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u][v] = g[v][u] = min(g[u][v], (ll)w);
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++)
    mp[temp[i]].push_back(i);

  int q;
  cin >> q;
  vector<vector<tuple<int, int, int>>> q1(n), q2(n);
  for (int i = 0; i < q; i++) {
    int u, v, k, b;
    cin >> u >> v >> k >> b;
    --u, --v, --k;
    k = min(k, (int)mp.size()-1);
    if (b) q1[k].emplace_back(u, v, i);
    else q2[k].emplace_back(u, v, i);
  }

  vector<ll> res(q);
  auto floyd_warshall = [&](auto a, auto b, auto qs) {
    vector<vector<ll>> d(n, vector<ll>(n, LLONG_MAX));
    for (int i = 0; i < n; i++) {
      d[i][i] = 0;
      for (int j = 0; j < n; j++)
        d[i][j] = g[i][j];
    }
    int pos = 0;
    for (auto it = a; it != b; it++, pos++) {
      for (auto k : it->second) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if (d[i][k] < LLONG_MAX and d[k][j] < LLONG_MAX)
              d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
          }
        }
      }
      for (auto [u, v, id] : qs[pos])
        res[id] = d[u][v];
    }
  };
  floyd_warshall(mp.rbegin(), mp.rend(), q1);
  floyd_warshall(mp.begin(), mp.end(), q2);

  for (auto x : res) cout << (x == LLONG_MAX ? -1 : x) << '\n';
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
