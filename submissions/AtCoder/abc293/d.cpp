#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

struct UFDS
{
  vector<int> ps, sz;

  UFDS(int n) : ps(n+1), sz(n+1, 1)
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
  }
};

void solve()
{
  int n, m;
  cin>> n>>m;
  UFDS ufds(n);
  set<int> cycles;
  for (int i = 0; i < m; i++)
  {
    int x, y;
    char c;
    cin >> x >> c >> y >> c;
    if (ufds.same_set(x, y))
      cycles.insert(ufds.find_set(x));
    else
      ufds.union_set(x, y);
  }

  auto con = 0, ncon = 0;
  for (int i = 1; i <= n; i++)
  {
    if (ufds.ps[i] != i) continue;
    (cycles.count(i) ? con++ : ncon++);
  }

  cout << con << ' ' << ncon << '\n';
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

