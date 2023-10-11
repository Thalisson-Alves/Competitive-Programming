#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n, q;
  cin >> n >> q;
 
  vector<int> f(n);
  for (auto &x : f) cin >> x, --x;
 
  vector<char> vis(n);
  vector<pair<int, int>> cycles_desc(n);
  for (int i = 0; i < n; i++)
  {
    if (vis[i]) continue;
 
    vector<int> v;
    v.reserve(n);
    int cur = i;
    while (not vis[cur])
    {
      v.push_back(cur);
      if (vis[cur]) break;
      vis[cur] = 1;
 
      cur = f[cur];
    }
 
    int pos = 0;
    for (pos = 0; pos < len(v); pos++)
      if (v[pos] == cur)
        break;
 
    dbg(i, pos, v);
    for (int j = 0; j < len(v); j++)
    {
      if (pos == len(v))
        cycles_desc[v[j]] = {len(v) - j + cycles_desc[cur].first, cycles_desc[cur].second};
      else
      {
        if (j < pos)
          cycles_desc[v[j]] = {pos - j, len(v) - pos};
        else
          cycles_desc[v[j]] = {0, len(v) - pos};
      }
    }
  }
 
  vector<int> ufds(n, -1), pos(n);
  vector<vector<int>> cycles(n);
 
  for (int i = 0; i < n; i++)
  {
    if (ufds[i] > -1) continue;
 
    if (cycles_desc[i].first)
    {
      int cur = i;
      while (ufds[cur] == -1 and cycles_desc[cur].first)
      {
        ufds[cur] = i;
        pos[cur] = len(cycles[i]);
        cycles[i].push_back(cur);
 
        cur = f[cur];
      }
      cycles[i].push_back(cur);
    }
    else
    {
      for (int cur = i; ufds[cur] == -1; cur = f[cur])
      {
        ufds[cur] = i;
        pos[cur] = len(cycles[i]);
        cycles[i].push_back(cur);
      }
    }
  }

  dbg(cycles);
  dbg(ufds);
  dbg(cycles_desc);
 
  while (q--)
  {
    int x, k;
    cin >> x >> k;
    x--;
 
    while (k and pos[x] + len(cycles[ufds[x]]) <= k and cycles_desc[ufds[x]].first)
    {
      int walk = min(len(cycles[ufds[x]]) - pos[x] - 1, k);
      dbg(ufds[x], pos[x], x, k, walk);
      k -= walk;
      x = cycles[ufds[x]][pos[x] + walk];
    }

    dbg(pos[x], ufds[x], x, k);

    int ans = -1;
    if (k == 0)
    {
      ans = x;
    }
    else if (pos[x] + k < len(cycles[ufds[x]]))
    {
      auto &cycle = cycles[ufds[x]];
      ans = cycle[pos[x] + k];
    }
    else
    {
      int parent = (cycles_desc[x].first ? cycles[ufds[x]].back() : x);
 
      auto &cycle = cycles[ufds[parent]];
      int remain = k - cycles_desc[x].first;
      ans = cycle[(pos[parent] + remain) % cycle.size()];
    }
 
    cout << ans + 1 << '\n';
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
