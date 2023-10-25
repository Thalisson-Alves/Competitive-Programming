#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

// optional<vector<int>> check_bipartite(const vector<vector<int>> &g) {
bool check_bipartite(const vector<vector<int>> &g) {
  vector<int> color(g.size(), -1);
  color[0] = 0;

  queue<int> q;
  q.push(0);

  while (not q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto x : g[cur]) {
      if (color[x] == color[cur])
        return false;
        // return {};

      if (color[x] == -1) {
        color[x] = color[cur]^1;
        q.push(x);
      }
    }
  }

  // return color;
  return true;
}

void solve()
{
  for (int n, m; cin >> n >> m, n; ) {
    vector<vector<int>>  g(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    cout << (check_bipartite(g) ? "" : "NOT ") << "BICOLORABLE.\n";
  }
}
 
int main()
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
