#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n';
#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

struct UFDS
{
  vector<int> ps, sz;

  UFDS(int n) : ps(n+1), sz(n+1)
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
  cin >> n >> m;
  UFDS ufds(n);
  for (int i = 0; i < m; i++)
  {
    int x; cin >> x;
    ufds.union_set(x, x+1);
  }
  set<int> todo;
  for (int i = 1; i <= n; i++) todo.insert(i);
  vector<int> ans;
  ans.reserve(n);
  while (not todo.empty())
  {
    auto x = *todo.begin();
    for (int i = n; i > 0; i--)
    {
      if (ufds.same_set(x, i))
      {
        ans.push_back(i);
        todo.erase(todo.find(i));
      }
    }
  }
  for (auto i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n-1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

