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

void graph_cycles(const vector<vector<int>> &g, int u, int p, vector<int> &ps, vector<int> &color, int &cn, vector<vector<int>> &cycles)
{
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
      cur = ps[cur];
      v.push_back(cur);
    }
    return;
  }

  ps[u] = p;
  color[u] = 1;
  for (auto v : g[u]) {
    if (v == ps[u]) continue;
    graph_cycles(g, v, u, ps, color, cn, cycles);
  }

  color[u] = 2;
}

vector<vector<int>> graph_cycles(const vector<vector<int>> &g, int u) {
  vector<int> ps(g.size(), -1), color(g.size());
  int cn = 0;
  vector<vector<int>> cycles;
  graph_cycles(g, u, -1, ps, color, cn, cycles);
  return cycles;
}

void solve()
{
  string s;
  cin >> s;
  vector<int> bs;
  for (auto i = 0; i < (int)s.size(); i++) {
    if (s[i] == 'B')
      bs.push_back(i);
  }
  bs.push_back((int)s.size());
  int sum = bs[0], mn = bs[0];
  for (int i = 1, x; i < int(bs.size()); i++)
    x = bs[i] - bs[i-1] - 1, sum += x, mn = min(mn, x);
  dbg(bs);
  cout << sum - mn << '\n';
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
