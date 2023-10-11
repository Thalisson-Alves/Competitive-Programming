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

void bellman_ford(const vector<vector<int>> &g, int s, vector<int> &p)
{
  int n = (int)g.size();

  vector<char> in_queue(n);
  queue<int> q;

  q.push(s);
  in_queue[s] = true;

  while (not q.empty())
  {
    int cur = q.front();
    q.pop();
    in_queue[cur] = false;

    for (auto to : g[cur])
    {
      if (p[to] < p[cur] - 1)
      {
        p[to] = p[cur] - 1;
        if (not in_queue[to])
        {
          q.push(to);
          in_queue[to] = true;
        }
      }
    }
  }
}

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> g(n);
  for (int i =0 ; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> p(n);
  for (int i = 0; i < k; i++)
  {
    int a, b;
    cin >> a >> b;
    --a;
    p[a] = b + 1;
  }

  vector<int> order;
  for (int i = 0; i < n; i++)
    if (p[i])
      order.push_back(i);
  sort(all(order), [&](int a, int b){return p[a] > p[b];});

  for (auto i : order)
    bellman_ford(g, i, p);
  dbg(p);

  vector<int> ans;
  for (int i = 0; i < n; i++)
    if (p[i])
      ans.push_back(i+1);

  cout << ans.size() << '\n';
  for (int i = 0; i < len(ans); i++)
    cout << ans[i] << " \n"[i == len(ans) - 1];
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
