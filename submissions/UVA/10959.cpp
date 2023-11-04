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
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  queue<int> q;
  q.push(0);
  vector<int> ans(n, -1);
  ans[0] = 0;
  while (not q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto x : g[cur]) {
      if (ans[x] != -1) continue;
      ans[x] = ans[cur] + 1;
      q.push(x);
    }
  }

  for (int i = 1; i < n; i++)
    cout << ans[i] << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    if (i > 1) cout << '\n';
    solve();
  }

  return 0;
}
