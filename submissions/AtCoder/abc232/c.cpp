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
  vector<vector<bool>> g1(n, vector<bool>(n)), g2 = g1;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g1[u][v] = 1;
    g1[v][u] = 1;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g2[u][v] = 1;
    g2[v][u] = 1;
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  do {
    bool can = 1;
    for (int i = 0; can and i < n; i++) {
      for (int j = i+1; can and j < n; j++) {
        if (g1[i][j] and !g2[order[i]][order[j]])
          can = false;
      }
    }
    if (can) {
      cout << "Yes\n";
      return;
    }
  } while (next_permutation(order.begin(), order.end()));
  cout << "No\n";
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
