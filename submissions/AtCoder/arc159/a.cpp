#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 42
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(const vector<vector<int>> &mat, int start, vector<vector<ll>> &dist)
{
  queue<pair<int, ll>> q;
  q.emplace(start, 1);

  vector<int> vis(mat.size());
  vis[start] = true;

  while (not q.empty())
  {
    auto [cur, d] = q.front(); q.pop();

    for (int x = 0; x < (int)mat.size(); x++)
    {
      if (mat[cur][x] == 0) continue;
      dist[start][x] = min(d, dist[start][x]);

      if (not vis[x])
        q.emplace(x, d+1);

      vis[x] = true;
    }
  }
}

void solve()
{
  ll n, k; cin >> n >> k;
  vector<vector<int>> mat(n, vector<int>(n));
  for (auto &row : mat) for (auto &x : row) cin >> x;
  vector<vector<ll>> dist(n, vector<ll>(n, LLONG_MAX));
  for (int i = 0; i < n; i++)
    bfs(mat, i, dist);

  dbg(dist);

  ll q; cin >> q;
  while (q--)
  {
    ll s, t; cin >> s >> t;
    s = (s-1)%n;
    t = (t-1)%n;

    cout << (dist[s][t] == LLONG_MAX ? -1 : dist[s][t]) << '\n';
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

