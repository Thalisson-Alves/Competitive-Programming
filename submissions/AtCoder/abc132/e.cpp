#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

int bfs(const vector<vector<int>> &g, int s, int t) {
  queue<pair<int, int>> q;
  q.emplace(s, 0);

  vector<vector<int>> dist(g.size(), vector<int>(3, INT_MAX));
  dist[s][0] = 0;

  vector<vector<char>> in_q(g.size(), vector<char>(3));
  in_q[s][0] = 1;

  while (not q.empty()) {
    auto [cur, mod] = q.front();
    q.pop();
    in_q[cur][mod] = 0;

    if (mod == 0 and cur == t) return dist[cur][mod] / 3;

    int mod2 = (mod+1)%3;
    for (auto x : g[cur]) {
      if (dist[cur][mod]+1 < dist[x][mod2]) {
        dist[x][mod2] = dist[cur][mod]+1;
        if (not in_q[x][mod2]) {
          q.emplace(x, mod2);
          in_q[x][mod2] = 1;
        }
      }
    }
  }

  return -1;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
  }
  int s, t;
  cin >> s >> t;
  --s, --t;

  cout << bfs(g, s, t) << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}
