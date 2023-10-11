#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void graph_cycles(const vector<vector<int>> &g, int u, int p, vector<int> &ps, vector<int> &color, int &cn, set<int> &cycles)
{
  if (cycles.size()) return;
  if (color[u] == 2) {
    return;
  }

  if (color[u] == 1) {
    cn++;
    int cur = p;
    set<int> st;
    st.insert(cur);
    while (cur != u) {
      cur = ps[cur];
      st.insert(cur);
    }

    vector<int> cnt(g.size());
    for (auto x : st) {
      for (auto y : g[x])
        if (st.count(y))
          cnt[y]++;
    }

    if (all_of(all(cnt), [](int x){return max(x, 1) == 1;}))
      cycles = st;

    return;
  }

  ps[u] = p;
  color[u] = 1;
  for (auto v : g[u]) {
    graph_cycles(g, v, u, ps, color, cn, cycles);
  }

  color[u] = 2;
}

set<int> graph_cycles(const vector<vector<int>> &g) {
  vector<int> ps(g.size(), -1), color(g.size());
  int cn = 0;
  set<int> cycles;
  for (int i = 0; i < (int)g.size(); i++)
    graph_cycles(g, i, -1, ps, color, cn, cycles);
  return cycles;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i =0 ;i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
  }
  auto res = graph_cycles(g);
  if (res.empty()) {
    cout << "-1\n";
    return;
  }
  cout << res.size() << '\n';
  for (auto v : res) {
    cout << v +1 << '\n';
  }
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}

