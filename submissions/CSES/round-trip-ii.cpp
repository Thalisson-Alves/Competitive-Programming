#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

bool has_cycle(const vector<vector<int>> &g, int s, vector<char> &vis, vector<char> &in_path, vector<int> *path = nullptr)
{
  vis[s] = in_path[s] = 1;
  if (path != nullptr)
    path->push_back(s);
  dbg(s, path);
  for (auto x : g[s])
  {
    if (!vis[x] && has_cycle(g, x, vis, in_path, path))
      return true;
    else if (in_path[x])
    {
      if (path != nullptr)
        path->push_back(x);
      return true;
    }
  }
  dbg(s, path);
  in_path[s] = 0;
  if (path != nullptr)
    path->pop_back();
  return false;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
  }
  dbg(g);

  vector<char> vis(n);
  for (int i = 0; i < n; i++)
  {
    if (vis[i]) continue;
    vector<char> in_path(n);
    vector<int> path;
    if (not has_cycle(g, i, vis, in_path, &path)) continue;

    stack<int> st;
    st.push(path.back());
    for (auto it = path.rbegin()+1; it != path.rend(); it++)
    {
      st.push(*it);
      if (*it == path.back()) break;
    }

    cout << st.size() << '\n';
    while (!st.empty())
    {
      cout << st.top()+1 << ' ';
      st.pop();
    }
    cout << '\n';
    return;
  }

  cout << "IMPOSSIBLE\n";
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
 
