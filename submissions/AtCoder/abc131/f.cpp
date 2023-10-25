#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

struct UFDS
{
  vector<int> ps, sz;
  int components;

  UFDS(int n) : ps(n), sz(n, 1), components(n)
  {
    iota(all(ps), 0);
  }

  int find_set(int x)
  {
    return (x == ps[x] ? x : (ps[x] = find_set(ps[x])));
  }

  bool same_set(int x, int y)
  {
    return find_set(x) == find_set(y);
  }

  void union_set(int x, int y)
  {
    x = find_set(x);
    y = find_set(y);
    
    if (x == y) return;

    if (sz[x] < sz[y])
      swap(x, y);

    ps[y] = x;
    sz[x] += sz[y];

    components--;
  }
};

constexpr ll SIZE = 1e5 + 1;
constexpr ll MAX = SIZE << 1;

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> g(MAX), gr(MAX);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    y += SIZE;
    g[x].push_back(y);
    gr[y].push_back(x);
  }

  UFDS ufds(MAX);
  for (int i = 0; i < MAX; i++) {
    if (ufds.sz[ufds.find_set(i)] > 1) continue;
    auto &x = gr[i];
    for (int j = 1; j < (int)x.size(); j++) {
      ufds.union_set(x[j], x[j-1]);
    }
  }

  vector<set<int>> con(MAX);
  for (int i = 0; i < MAX; i++) {
    con[ufds.find_set(i)].insert(all(g[i]));
  }

  ll ans = 0;
  for (int i = 0; i < MAX; i++) {
    ans += (ll)(con[ufds.find_set(i)].size() - g[i].size());
  }
  cout << ans << '\n';
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
 
  return 0;
}
