#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

optional<vector<int>> check_bipartite(const vector<vector<int>> &g) {
  vector<int> color(g.size(), -1);
  for (int i = 0; i < (int)g.size(); i++) {
    if (color[i] != -1) continue;
    color[i] = 0;

    queue<int> q;
    q.push(i);

    while (not q.empty()) {
      auto cur = q.front();
      q.pop();

      for (auto x : g[cur]) {
        if (color[x] == color[cur])
          return {};

        if (color[x] == -1) {
          color[x] = color[cur]^1;
          q.push(x);
        }
      }
    }
  }
  for (auto &x : color) if (x == -1) x = 0;

  return color;
}

void solve()
{
  int n, m;
  cin >>  n >> m;
  vector<int> a(m), b(m);
  for (auto & x :a ) cin >> x, --x;
  for (auto & x :b ) cin >> x, --x;

  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  if (check_bipartite(g))
    cout << "Yes\n";
  else
    cout << "No\n";
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
