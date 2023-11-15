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
ll oo = 1e18;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  int n;
  cin >> n;
  vector<set<int>> g(n);
 
  for (int i = 0; i < n-1; i++)
  {
    int x, y;
    cin >> x >> y;
    g[x-1].insert(y-1);
    g[y-1].insert(x-1);
  }
 
  queue<int> pq;
  for (int i = 0; i < n; i++)
    if (g[i].size() == 1)
      pq.emplace(i);
 
  vector<int> roots(n);
  vector<char> vis(n);
  while (not pq.empty())
  {
    auto start = pq.front(); pq.pop();
    if (vis[start]) continue;
 
    int root = *g[start].begin();
    vis[root] = 1;
    for (auto x : g[root])
    {
      vis[x] = 1;
      for (auto y : g[x])
        if (y != root)
        {
          g[y].erase(x);
          if (g[y].size() == 1)
            pq.push(y);
        }
 
      g[x] = {root};
    }
 
    roots[root] = g[root].size();
  }
 
  dbg(roots);
 
  vector<int> ans;
  for (auto x : roots)
    if (x) ans.push_back(x);
  sort(all(ans));
  for (int i = 0 ; i < (int)ans.size(); i++)
    cout << ans[i] << " \n"[i == (int)ans.size() - 1];
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

