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

struct BitGraph
{
  vector<vector<char>> g;

  enum class Dir { UP, RIGHT, DOWN, LEFT };

  BitGraph(int n, int m, char value = 0) : g(n, vector<char>(m, value)) {}

  inline void set(int x, int y, Dir dir)
  {
    g[x][y] |= 1 << static_cast<int>(dir);
  }

  inline bool get(int x, int y, Dir dir) const
  {
    return g[x][y] & (1 << static_cast<int>(dir));
  }

  inline char get(int x, int y) const
  {
    return g[x][y];
  }
};

int dfs(const BitGraph &g, int sx, int sy, vector<vector<char>> &vis)
{
  stack<pair<int, int>> st;
  st.emplace(sx, sy);

  vis[sx][sy] = 1;
  int res = 0;

  while (not st.empty())
  {
    auto [x, y] = st.top();
    st.pop();
    res++;

    if (x > 0 and !g.get(x, y, BitGraph::Dir::DOWN) and !vis[x-1][y])
    {
      st.emplace(x-1, y);
      vis[x-1][y] = 1;
    }
    if (x < len(g.g)-1 and !g.get(x, y, BitGraph::Dir::UP) and !vis[x+1][y])
    {
      st.emplace(x+1, y);
      vis[x+1][y] = 1;
    }
    if (y > 0 and !g.get(x, y, BitGraph::Dir::LEFT) and !vis[x][y-1])
    {
      st.emplace(x, y-1);
      vis[x][y-1] = 1;
    }
    if (y < len(g.g[0])-1 and !g.get(x, y, BitGraph::Dir::RIGHT) and !vis[x][y+1])
    {
      st.emplace(x, y+1);
      vis[x][y+1] = 1;
    }
  }

  return res;
}

void solve()
{
  int n;
  cin >> n;
  BitGraph g(1e3+2, 1e3+2);

  int x, y;
  cin >> y >> x;
  for (int i = 0; i < n; i++)
  {
    int nx, ny;
    cin >> ny >> nx;

    if (nx == x)
    {
      for (int j = min(y, ny); j < max(y, ny); j++)
      {
        g.set(nx-1, j, BitGraph::Dir::UP);
        g.set(nx, j, BitGraph::Dir::DOWN);
      }
    }
    else
    {
      for (int j = min(x, nx); j < max(x, nx); j++)
      {
        g.set(j, ny-1, BitGraph::Dir::RIGHT);
        g.set(j, ny, BitGraph::Dir::LEFT);
      }
    }

    x = nx;
    y = ny;
  }

  vector<vector<char>> vis(len(g.g), vector<char>(len(g.g[0])));
  dfs(g, 0, 0, vis);
  int ans = 0;

  for (int i = 0; i < len(g.g); i++)
  {
    for (int j = 0; j < len(g.g[0]); j++)
    {
      if (!vis[i][j])
      {
        ans = max(ans, dfs(g, i, j, vis));
      }
    }
  }

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
    solve();
 
  return 0;
}
