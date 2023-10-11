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

vector<int> bfs(const vector<unordered_set<int>> &g, int s)
{
  vector<int> dist(g.size(), -1);
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  vector<int> came_from(g.size(), -1);

  while (not q.empty())
  {
    auto cur = q.front();
    q.pop();

    for (auto x : g[cur])
    {
      if (dist[x] >= dist[cur] + 1)
        continue;

      dist[x] = dist[cur] + 1;
      came_from[x] = cur;
      q.push(x);
    }
  }

  return came_from;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<unordered_set<int>> g(n), gr(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].insert(b);
    gr[b].insert(a);
  }

  auto came = bfs(g, 0);

  if (came.back() == -1)
    cout << "IMPOSSIBLE\n";
  else
  {
    vector<int> path;
    for (int i = n - 1; i != -1; i = came[i])
      path.push_back(i);
    reverse(all(path));
    cout << path.size() << '\n';
    for (auto x : path)
      cout << x + 1 << ' ';
    cout << '\n';
  }
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
 
