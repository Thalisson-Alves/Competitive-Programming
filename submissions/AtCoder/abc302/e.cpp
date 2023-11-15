#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
 
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
    auto px = find_set(x);
    auto py = find_set(y);
    
    if (px == py) return;

    if (sz[px] < sz[py])
      swap(px, py);

    ps[py] = px;
    sz[px] += sz[py];
    sz[py] = sz[px];

    components -= (sz[x] == 1) + (sz[y] == 1);
  }

  void remove_set(int x)
  {
    sz[x] = 1;
    ps[x] = x;

    components++;
  }
};

void solve()
{
  int n, q;
  cin >> n >> q;

  vector<set<int>> v(n);
  set<int> ans;
  for (int i = 0; i < n; i++)
    ans.insert(i);
  while (q--)
  {
    int t, x;
    cin >> t >> x;
    x--;
    if (t == 1)
    {
      int y;
      cin >> y;
      y--;

      ans.erase(x);
      ans.erase(y);

      v[x].insert(y);
      v[y].insert(x);
    }
    else
    {
      for (auto a : v[x])
      {
        v[a].erase(x);
        if (v[a].empty())
          ans.insert(a);
      }

      v[x].clear();
      ans.insert(x);
    }

    cout << ans.size() << '\n';
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

