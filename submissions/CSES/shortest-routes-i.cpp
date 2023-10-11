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

vector<ll> dijkstra(const vector<vector<pair<int, int>>> &g, int start)
{
  vector<ll> dist(g.size(), LLONG_MAX);
  dist[start] = 0;
  auto cmp = [&dist] (int a, int b) {
    return dist[b] < dist[a];
  };

  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
  pq.emplace(start);

  while (not pq.empty())
  {
    dbg(pq);
    auto cur = pq.top(); pq.pop();

    for (auto x : g[cur])
    {
      if (dist[x.second] <= x.first + dist[cur]) continue;

      pq.emplace(x.second);
      dist[x.second] = x.first + dist[cur];
    }
  }
  return dist;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  for (int a, b, c; cin >> a >> b >> c; g[a-1].emplace_back(c, b-1));

  dbg(g);
  auto ans = dijkstra(g, 0);
  cout << "0";
  for (int i = 1; i < n; i++)
    cout << ' ' << ans[i];
  cout << '\n';
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

