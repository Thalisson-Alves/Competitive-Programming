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

template<typename T>
vector<T> split(const string &s)
{
  vector<T> ans;
  stringstream ss(s);
  for (T x; ss >> x; ans.push_back(x));
  return ans;
}
 
ll fpow(ll x, ll p, const ll MOD)
{
  if (p == 0) return 1;
  auto ans = fpow(x, p >> 1, MOD);
  ans = ans * ans % MOD;
  if (p & 1) ans = ans * x % MOD;
  return ans;
}

string bfs(const vector<string> &g)
{
  vector<char> vis(g.size() * g[0].size());

  using T = tuple<int, bool, int>;
  priority_queue<T, vector<T>, greater<T>> q;

#define CVT(x, y) (x*(int)g[0].size()+y)
#define ROW(x) ((int)(x/g[0].size()))
#define COL(x) ((int)(x%g[0].size()))
#define VMAT(x) (g[ROW(x)][COL(x)])
#define IS_EXIT(x) (VMAT(x) != '#' and (ROW(x) == 0 or ROW(x) == (int)g.size() - 1 or COL(x) == 0 or COL(x) == (int)g[0].size() - 1))
  int start = -1;
  for (int i = 0; i < (int)g.size(); i++)
  {
    for (int j = 0 ; j < (int)g[i].size(); j++)
    {
      auto cur = CVT(i, j);
      if (g[i][j] == 'A')
      {
        start = cur;
        q.emplace(0, true, start);
        if (IS_EXIT(start))
        {
          cout << "YES\n0\n";
          exit(0);
        }
        vis[start] = 1;
      }
      else if (g[i][j] == 'M')
      {
        q.emplace(0, false, cur);
        vis[cur] = 1;
      }
    }
  }
  vector<int> came_from(g.size()*g[0].size(), -1);

  int end = -1;
  while (not q.empty())
  {
    auto [depth, is_player, cur] = q.top(); q.pop();

    if (is_player and IS_EXIT(cur))
    {
      end = cur;
      break;
    }

    for (auto [dx, dy] : dir4)
    {
      int x = dx + ROW(cur);
      int y = dy + COL(cur);

      auto next = CVT(x, y);
      if (x >= 0 and x < (int)g.size() and y >= 0 and y < (int)g[0].size() and not vis[next] and g[x][y] == '.')
      {
        dbg(next, x, y);
        q.emplace(depth + 1, is_player, next);
        vis[next] = 1;
        if (is_player)
          came_from[next] = cur;
      }
    }
  }

  dbg(came_from);
  if (end == -1) return "";

  string path;
  for (auto cur = end, prev = came_from[cur]; cur != start and prev != -1; cur = prev, prev = came_from[prev])
  {
    dbg(ROW(cur), COL(cur));
    dbg(ROW(prev), COL(prev));
    if (abs(cur - prev) == 1)
      path += (cur > prev ? 'R' : 'L');
    else
      path += (cur > prev ? 'D' : 'U');
  }

  reverse(all(path));

  return path;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (auto &x : v) cin >> x;

  auto path = bfs(v);
  if (not path.empty())
  {
    cout << "YES\n";
    cout << path.size() << '\n';
    cout << path << '\n';
    return;
  }

  cout << "NO\n";
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

