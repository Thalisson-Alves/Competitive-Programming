#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
using ii = pair<int, int>;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

int bfs(const vector<set<int>> &v, const vector<vector<int>> &g)
{
  queue<pair<int, int>> q;
  vector<char> vis(g.size()), vis2(v.size());

  for (auto x : g[0])
  {
    q.emplace(0, x);
    vis2[x] = 1;
    if (*v[x].rbegin() == (int)g.size() - 1)
      return 0;
  }

  while (not q.empty())
  {
    auto [cost, cur] = q.front(); q.pop();

    for (auto i : v[cur])
    {
      if (not vis[i])
      {
        vis[i] = 1;
        for (auto x : g[i])
        {
          if (vis2[x]) continue;

          vis2[x] = 1;
          if (*v[x].rbegin() == (int)g.size() - 1)
            return cost + 1;

          q.emplace(cost + 1, x);
        }
      }
    }
  }

  return -1;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<set<int>> v(n);
  vector<vector<int>> g(m);
  for (int i = 0; i < n; i++)
  {
    int a; cin >> a;
    for (int x; a-- and cin >> x; x--, v[i].insert(x), g[x].push_back(i));
  }

  cout << bfs(v, g) << '\n';
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
 
