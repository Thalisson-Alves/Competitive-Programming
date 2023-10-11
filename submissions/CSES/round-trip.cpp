#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

vector<int> dfs(const vector<vector<int>> &g, int s, vector<int> &came_from)
{
  dbg(s, came_from);
  for (auto x : g[s])
  {
    if (came_from[s] != -1 and came_from[s] == x) continue;
    dbg(s, x);
    if (came_from[x] != -1)
    {
      came_from[x] = s;
      dbg(s, x);
      vector<int> path;
      path.push_back(x);
      for (auto c = came_from[x]; c != x and c != -1; c = came_from[c])
        path.push_back(c);
      path.push_back(x);
      return path;
    }
 
    came_from[x] = s;
    auto p = dfs(g, x, came_from);
    came_from[x] = -1;
    if (p.size()) return p;
  }
  return {};
}

struct UFDS
{
  vector<int> ps, sz;
  int components;

  UFDS(int n) : sz(n+1, 1), ps(n+1), components(n)
  {
    iota(all(ps), 0);
  }

  int find_set(int x)
  {
    return (x == ps[x] ? x : (ps[x] = find_set(ps[x])));
  }

  bool same_set(int x, int y)
  {
    return find_set(x) == find_set(y);
  }

  void union_set(int x, int y)
  {
    x = find_set(x);
    y = find_set(y);
    
    if (x == y) return;

    if (sz[x] < sz[y])
     swap(x, y);

    ps[y] = x;
    sz[x] += sz[y];

    components--;
  }
};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  UFDS ufds(n);
  for (int i = 0, a, b; i < m; i++)
  {
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
    ufds.union_set(a, b);
  }
  dbg(ufds.ps, ufds.sz);
 
  map<int, int> mp;
  for (int i = 0; i < n; i++)
    mp[ufds.find_set(i)] += g[i].size();
 
  vector<int> came_from(n, -1);
  for (auto [a, b] : mp)
  {
    dbg(ufds.sz, a);
    dbg(ufds.sz[a], b, b / 2);
    if (ufds.sz[a] <= b / 2)
    {
      auto path = dfs(g, a, came_from);
      cout << path.size() << '\n';
      for (int i = 0; i < (int)path.size(); i++)
        cout << path[i] + 1 << " \n"[i == (int)path.size()-1];
      return;
    }
  }
  cout << "IMPOSSIBLE\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

