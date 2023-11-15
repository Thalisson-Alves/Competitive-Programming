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

ll oo = 1e18;

vector<ll> bfs(const vector<string> &v, int start)
{
  vector<ll> dist(v.size() * v[0].size(), oo);

  queue<int> q;
  q.push(start);
  dist[start] = 0;

  const int W = (int)v[0].size();

  while (not q.empty())
  {
    auto cur = q.front(); q.pop();

    for (auto [dx, dy] : dir4)
    {
      int x = cur / W + dx;
      int y = cur % W + dy;

      if (x < 0 or y < 0 or x >= (int)v.size() or y >= (int)v[0].size() or v[x][y] == '#' or dist[x*W+y] <= dist[cur] + 1)
        continue;

      q.emplace(x*W+y);
      dist[x*W+y] = dist[cur] + 1;
    }
  }

  return dist;
}

vector<ll> translate_dists(const vector<ll> &&dist, const vector<int> &coins, int start, int end)
{
  vector<ll> ns(coins.size() + 2);
  ns[0] = dist[start];
  for (int i = 0; i < (int)coins.size(); i++)
    ns[i+1] = dist[coins[i]];
  ns[ns.size() - 1] = dist[end];
  return ns;
}

ll tsp(int i, int mask, const vector<vector<ll>> &dist, vector<vector<ll>> &memo)
{
  if (mask == (1 << dist.size()) - 1)
    return dist[i].back();

  if (memo[i][mask] != -1)
    return memo[i][mask];

  ll ans = oo;
  for (int j = 1; j < (int)dist.size() - 1; j++)
  {
    if (mask & (1ll << j))
      continue;

    ans = min(ans, tsp(j, mask | (1 << j), dist, memo) + dist[i][j]);
  }

  return memo[i][mask] = ans;
}

template<typename T>
int popcount(T x)
{
  int res = 0;
  for (; x; ++res)
    x &= x - 1;
  return res;
}

void solve()
{
  int h, w, t;
  cin >> h >> w >> t;
  vector<string> v(h);
  for (auto &x : v) cin >> x;

  int start = 0, end = 0;
  vector<int> coins;

  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      switch (v[i][j])
      {
        case 'S':
          start = i * w + j;
          break;
        case 'G':
          end = i * w + j;
          break;
        case 'o':
          coins.push_back(i*w + j);
      }

  vector<vector<ll>> dists(coins.size() + 2);
  dists[0] = translate_dists(bfs(v, start), coins, start, end);
  dists[coins.size()+1] = translate_dists(bfs(v, end), coins, start, end);

  for (int i = 0; i < (int)coins.size(); i++)
    dists[i+1] = translate_dists(bfs(v, coins[i]), coins, start, end);

  dbg(dists);

  vector<vector<ll>> memo(dists.size(), vector<ll>(1<<dists.size(), -1));
  ll ans = -1;
  for (int i = 0; i < (1<<(dists.size() - 2)); i++)
  {
    auto mask = (i << 1) | 1 | (1 << (dists.size() - 1));
    auto x = tsp(0, mask, dists, memo);
    dbg(bitset<21>(mask), x);
    if (x <= t)
      ans = max(ans, (ll)coins.size() - popcount(i));
  }

  dbg(ans);
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
 
