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

void floyd_warshall(vector<vector<ll>> &dist)
{
  int n = dist.size();

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (dist[k][j] != LLONG_MAX and dist[i][k] != LLONG_MAX)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void solve()
{
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<ll>> dist(n, vector<ll>(n, LLONG_MAX));
  for (int i = 0; i < n; i++)
    dist[i][i] = 0;
  for (int i = 0; i < m; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    dist[a][b] = min({dist[a][b], dist[b][a], c});
    dist[b][a] = dist[a][b];
  }

  floyd_warshall(dist);

  dbg(dist);
  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    cout << (dist[a-1][b-1] == LLONG_MAX ? -1 : dist[a-1][b-1]) << '\n';
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

