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

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i =0 ;i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int res = 0;
  vector<int> color(g.size(), -1);

  for (int i = 0; i < (int)g.size(); i++) {
    if (color[i] != -1) continue;
    color[i] = 0;

    queue<int> q;
    q.push(i);

    array<int, 2> cnt = {1, 0};

    while (not q.empty()) {
      auto cur = q.front();
      q.pop();

      for (auto x : g[cur]) {
        if (color[x] == color[cur]) {
          cout << "-1\n";
          return;
        }

        if (color[x] == -1) {
          color[x] = color[cur]^1;
          cnt[color[x]]++;
          q.push(x);
        }
      }
    }

    res += max(1, min(cnt[0],cnt[1]));
  }
  cout << res << '\n';
}
 
int main()
{
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

