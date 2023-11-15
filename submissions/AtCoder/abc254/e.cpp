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

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

ll bfs(const vector<vector<int>> &g, int x, int k)
{
  queue<pair<ll, ll>> q;
  q.emplace(x, 0);

  vector<char> vis(g.size());
  vis[x] = true;

  ll ans = 0;
  while (not q.empty())
  {
    auto [cur, depth] = q.front(); q.pop();

    ans += cur + 1;

    if (depth == k) continue;

    for (auto a : g[cur])
    {
      if (vis[a]) continue;

      q.emplace(a, depth + 1);
      vis[a] = true;
    }
  }

  return ans;
}

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  int q;
  cin >> q;
  while (q--)
  {
    int x, k;
    cin >> x >> k;

    auto ans = bfs(g, x-1, k);
    cout << ans << '\n';
  }
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

