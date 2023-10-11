#include <bits/stdc++.h>
using namespace std;
 
// #ifdef DEBUG
// #include "debug.cpp"
// #else
// #define dbg(...)
// #endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

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

void solve()
{
  int n, k, l;
  cin >> n >> k >> l;
  UFDS u1(n), u2(n), u3(n);
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    u1.union_set(u, v);
  }
  for (int i = 0; i < l; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    u2.union_set(u, v);
  }

  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    mp[make_pair(u1.find_set(i), u2.find_set(i))]++;
  }

  for (int i = 0; i < n; i++) {
    cout << mp[make_pair(u1.find_set(i), u2.find_set(i))] << ' ';
  }
  cout << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}
