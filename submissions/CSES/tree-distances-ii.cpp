#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()

#define int ll
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void dfs(const vector<vector<int>> &g, int u, int p, vector<int> &in, vector<int> &size) {
  for (auto x : g[u]) {
    if (x != p) {
      dfs(g, x, u, in, size);
      size[u] += size[x];
      in[u] += in[x] + size[x];
    }
  }
}

void dfs2(const vector<vector<int>> &g, int u, int p, const vector<int> &in, const vector<int> &size, vector<int> &out) {
  int sib = 0;
  for (auto x : g[u])
    if (x != p)
      sib += in[x] + size[x] * 2;

  for (auto x: g[u]) {
    if (x != p) {
      out[x] = (out[u] + ((int)g.size()-size[u]+1) + sib - (in[x] + size[x] * 2));
      dfs2(g, x, u, in, size, out);
    }
  }
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> in(n), size(n, 1), out(n);
  dfs(g, 0, -1, in, size);
  dfs2(g, 0, -1, in, size, out);

  for (int i = 0; i < n; i++) {
    cout << in[i] + out[i] << ' ';
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
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}
