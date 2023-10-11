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

struct SmallToLarge
{
  vector<vector<int>> tree, vis_childs;
  vector<int> sizes, values, ans;
  set<int> cnt;

  SmallToLarge(vector<vector<int>> &&g, vector<int> &&v) : tree(g), vis_childs(g.size()), sizes(g.size()), values(v), ans(g.size())
  {
    update_sizes(0);
  }

  inline void add_value(int u)
  {
    cnt.insert(values[u]);
  }

  inline void remove_value(int u)
  {
    cnt.erase(values[u]);
  }

  inline void update_ans(int u)
  {
    ans[u] = (int)cnt.size();
  }

  void dfs(int u, int p = -1, bool keep=true)
  {
    int mx = -1;
    for (auto x : tree[u])
    {
      if (x == p) continue;

      if (mx == -1 or sizes[mx] < sizes[x])
        mx = x;
    }

    for (auto x : tree[u])
    {
      if (x != p and x != mx)
        dfs(x, u, false);
    }

    if (mx != -1)
    {
      dfs(mx, u, true);
      swap(vis_childs[u], vis_childs[mx]);
    }

    vis_childs[u].push_back(u);
    add_value(u);

    for (auto x : tree[u])
    {
      if (x != p and x != mx)
      {
        for (auto y : vis_childs[x])
        {
          add_value(y);
          vis_childs[u].push_back(y);
        }
      }
    }

    update_ans(u);

    if (!keep)
    {
      for (auto x : vis_childs[u])
        remove_value(x);
    }
  }

  void update_sizes(int u, int p = -1)
  {
    sizes[u] = 1;
    for (auto x : tree[u])
    {
      if (x != p)
      {
        update_sizes(x, u);
        sizes[u] += sizes[x];
      }
    }
  }
};

void solve()
{
  int n;
  cin >> n;
  vector<int> cs(n);
  for (auto &x : cs) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  SmallToLarge stl(move(g), move(cs));
  stl.dfs(0);

  for (int i = 0; i < n; i++)
    cout << stl.ans[i] << " \n"[i == n-1];
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
