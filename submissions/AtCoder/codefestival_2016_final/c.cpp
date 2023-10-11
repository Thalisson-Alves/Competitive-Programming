#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n), lang(m);
  for (int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    g[i].resize(k);
    for (auto &j : g[i])
    {
      cin >> j;
      --j;

      lang[j].push_back(i);
    }
  }

  vector<char> vis(n), vis_lang(m);
  vis[0] = 1;

  queue<int> q;
  q.push(0);

  while (not q.empty())
  {
    auto cur = q.front();
    q.pop();

    for (auto i : g[cur])
    {
      if (vis_lang[i]) continue;
      vis_lang[i] = 1;

      for (auto j : lang[i])
      {
        if (vis[j]) continue;
        q.push(j);
        vis[j] = 1;
      }
    }
  }

  cout << (all_of(all(vis), [](auto c) {return c;}) ? "YES" : "NO") << '\n';
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
