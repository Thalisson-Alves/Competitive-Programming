#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define NDEBUG
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<set<int>> g(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a>> b;
    --a, --b;
    g[a].insert(b);
    g[b].insert(a);
  }

  vector<int> to_remove;
  int ans = 0;
  do
  {
    to_remove.clear();
    dbg(g);
    for (int i = 0; i < n; i++)
    {
      if (g[i].size() != 1)
        continue;

      to_remove.push_back(i);
    }

    ans += not to_remove.empty();
    dbg(to_remove);
    for (int i = 0; i < n; i++)
      for (auto x : to_remove)
        g[i].erase(x);
    for (auto x : to_remove)
      g[x].clear();
  } while (to_remove.size());
  cout << ans << '\n';
}

int main()
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

