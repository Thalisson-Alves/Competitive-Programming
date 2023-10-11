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

map<pair<int, int>, int> deps;
void graph_cycles(const vector<vector<int>> &g, int u, int p, vector<int> &ps, vector<int> &color, int &cn, vector<vector<int>> &cycles, int ua, int ub)
{
  if (cycles.size()) return;
  if (color[u] == 2) {
    return;
  }

  if (color[u] == 1) {
    cn++;
    int cur = p;
    cycles.emplace_back();
    auto &v = cycles.back();
    v.push_back(cur);
    while (cur != u) {
      deps[make_pair(cur,ps[cur])]++;
      cur = ps[cur];
      v.push_back(cur);
    }
    reverse(all(v));
    return;
  }

  ps[u] = p;
  color[u] = 1;
  for (auto v : g[u]) {
    if (u != ua or v != ub)
      graph_cycles(g, v, u, ps, color, cn, cycles, ua, ub);
  }

  color[u] = 2;
}

vector<vector<int>> graph_cycles(const vector<vector<int>> &g, int ua=-1, int ub=-1) {
  vector<int> ps(g.size(), -1), color(g.size());
  int cn = 0;
  vector<vector<int>> cycles;
  for (int i = 0; i < (int)g.size(); i++)
    graph_cycles(g, i, -1, ps, color, cn, cycles, ua,ub);
  return cycles;
}

void solve()
{
  int n, m;
  cin >> n>> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
  }

  auto c = graph_cycles(g);
  if (c.empty()) {
    cout << "YES\n";
    return;
  }

  auto &cy = *min_element(all(c), [](auto &a, auto &b){return a.size() < b.size();});
  cy.push_back(cy.front());
  dbg(cy);
  for (int i = (int)cy.size() - 1; i; i--) {
    int a = c[0][i-1];
    int b = c[0][i];
    if (graph_cycles(g, a, b).empty()) {
      dbg(a, b);
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
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

