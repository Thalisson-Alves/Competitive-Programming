#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

// Directed Edges
vector<int> euler_cycle(vector<vector<int>> &g, int u)
{
  vector<int> res;
 
  stack<int> st;
  st.push(u);
  while (!st.empty())
  {
    auto cur = st.top();
    if (g[cur].empty()) {
      res.push_back(cur);
      st.pop();
    } else {
      auto next = g[cur].back();
      st.push(next);
 
      g[cur].pop_back();
    }
  }
 
  for (auto &x : g)
    if (!x.empty())
      return {};
 
  return res;
}
 
// Undirected Edges
vector<int> euler_cycle(vector<set<int>> &g, int u)
{
  vector<int> res;
 
  stack<int> st;
  st.push(u);
  while (!st.empty())
  {
    auto cur = st.top();
    if (g[cur].empty()) {
      res.push_back(cur);
      st.pop();
    } else {
      auto next = *g[cur].begin();
      st.push(next);
 
      g[cur].erase(next);
      g[next].erase(cur);
    }
  }
 
  for (auto &x : g)
    if (!x.empty())
      return {};
 
  return res;
}

// Directed Edges
vector<int> euler_path(vector<vector<int>> &g, int first)
{
  {
    int n = (int)g.size();
    vector<int> in(n), out(n);
    for (int i = 0; i < n; i++)
      for (auto x : g[i])
        in[x]++, out[i]++;

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++)
      if (in[i] == out[i]) c++;
      else if (in[i] - out[i] == 1) b++;
      else if (in[i] - out[i] == -1) a++;

    if (c != n-2 or a != 1 or b != 1) return {};
  }

  auto res = euler_cycle(g, first);
  if (res.empty()) return res;
 
  reverse(all(res));
  return res;
}

// Undirected edges
vector<int> euler_path(vector<set<int>> &g, int first)
{
  int n = (int)g.size();
  int v1 = -1, v2 = -1;
  {
    bool bad = false;
    for (int i = 0; i < n; i++)
      if (g[i].size() & 1)
      {
        if (v1 == -1) v1 = i;
        else if (v2 == -1) v2 = i;
        else bad = true;
      }
 
    if (bad or (v1 != -1 and v2 == -1)) return {};
  }

  if (v1 != -1)
  {
    // insert cycle
    g[v1].insert(v2);
    g[v2].insert(v1);
  }
 
  auto res = euler_cycle(g, first);
  if (res.empty()) return res;
 
  if (v1 != -1)
  {
    for (int i = 0; i + 1 < (int)res.size(); i++)
    {
      if ((res[i] == v1 and res[i+1] == v2) ||
          (res[i] == v2 and res[i+1] == v1)) {
        vector<int> res2;
        for (int j = i + 1; j < (int)res.size(); j++)
          res2.push_back(res[j]);
        for (int j = 1; j <= i; j++)
          res2.push_back(res[j]);
        res = res2;
        break;
      }
    }
  }
 
  reverse(all(res));
  return res;
}
 
void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
  }
 
  auto res = euler_path(g, 0);
  if ((int)res.size() != m+1 or res.front() != 0 or res.back() != n-1)
    cout << "IMPOSSIBLE\n";
  else
  {
    for (int i = 0; i < (int)res.size(); i++)
      cout << res[i] + 1 << " \n"[i == (int)res.size() - 1];
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
