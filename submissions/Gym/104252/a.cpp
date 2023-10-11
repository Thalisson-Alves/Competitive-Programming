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

void dfs(const vector<vector<int>> &g, int u, const int cant, vector<bool> &vis) {
  vis[u] = 1;
  for (auto x : g[u]) {
    if (x != cant and not vis[x]) {
      dfs(g, x, cant, vis);
    }
  }
}

void solve()
{
  int n;
  cin >> n;
  vector<pair<int, int>> ask(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    auto &[x, y] = ask[i];
    cin >> x >> y;
    --x, --y;
    g[x].push_back(i);
    g[y].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    vector<bool> v1(n), v2(n), v3(n);
    bool lose = false;
    dfs(g, ask[i].first, i, v1);
    dfs(g, ask[i].second, i, v2);
    dfs(g, i, i, v3);

    for (int j = 0; not lose and j < n; j++) {
      if (v1[j] and v2[j] and v3[j]) lose = true;
    }

    cout << "NY"[lose];
  }
  cout << '\n';
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
