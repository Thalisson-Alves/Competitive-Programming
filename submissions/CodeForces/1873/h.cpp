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

void has_cycle(const vector<vector<int>> &g, int u, int p, vector<int> &ps, vector<int> &color, int &cn, set<int> &cycles)
{
  if (color[u] == 2) {
    return;
  }

  if (color[u] == 1) {
    cn++;
    int cur = p;
    cycles.insert(cur);
    while (cur != u) {
      cur = ps[cur];
      cycles.insert(cur);
    }
    return;
  }

  ps[u] = p;
  color[u] = 1;
  for (auto v : g[u]) {
    if (v == ps[u]) continue;
    has_cycle(g, v, u, ps, color, cn, cycles);
  }

  color[u] = 2;
}

void solve()
{
  int n, a, b;
  cin >> n >> a >> b;
  --a, --b;
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dbg(g);

  vector<int> ps(n, -1), color(n);
  int cn = 0;
  set<int> cycles;
  has_cycle(g, 0, -1, ps, color, cn, cycles);
  dbg(cycles);

  queue<pair<int, bool>> q;
  q.emplace(a, 0);
  if (a != b)
    q.emplace(b, 1);
  vector<char> vis(n);
  vis[a] = vis[b] = 1;
  while (not q.empty()) {
    auto [cur, is_player] = q.front();
    q.pop();

    dbg(cur, is_player);

    if (is_player and cycles.count(cur)) {
      cout << "YES\n";
      return;
    }

    for (auto x : g[cur]) {
      if (not vis[x]) {
        vis[x] = 1;
        q.emplace(x, is_player);
      }
    }
  }

  cout << "NO\n";
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}
