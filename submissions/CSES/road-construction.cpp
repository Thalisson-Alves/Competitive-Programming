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
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

struct UFDS
{
  vector<int> ps, sz;
  int components;

  UFDS(int n) : ps(n+1), sz(n+1, 1), components(n)
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

void solve()
{
  int n, m;
  cin >> n >> m;

  UFDS ufds(n);
  int mx = 0;
  for (int a, b; cin >> a >> b;)
  {
    ufds.union_set(a, b);
    if (ufds.sz[ufds.find_set(mx)] < ufds.sz[ufds.find_set(a)])
      mx = a;

    cout << ufds.components << ' ' << ufds.sz[ufds.find_set(mx)] << '\n';
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
 
