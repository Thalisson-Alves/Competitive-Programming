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
ll oo = 1e18;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

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
  for (int i = 0; i < m; i++)
  {
    int a, b; cin >> a >> b;
    ufds.union_set(a-1, b-1);
  }

  int k;
  cin >> k;
  vector<set<int>> cant(n);
  for (int i = 0; i < k; i++)
  {
    int x, y;
    cin >> x >> y;
    --x, --y;

    x = ufds.find_set(x);
    y = ufds.find_set(y);

    cant[x].insert(y);
    cant[y].insert(x);
  }

  dbg(cant);
  dbg(ufds.ps);

  int q;
  cin >> q;
  while (q--)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;

    dbg(ufds.find_set(a), ufds.find_set(b));
    cout << (cant[ufds.find_set(a)].count(ufds.find_set(b)) ? "No" : "Yes") << '\n';
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

