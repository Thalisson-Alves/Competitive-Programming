#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()

using ll = long long;
 
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
 
vector<tuple<ll, int, int>> kruskal(int n, vector<tuple<ll, int, int>> &edges)
{
  UFDS ufds(n);
  vector<tuple<ll, int, int>> ans;
 
  sort(all(edges));
  for (auto [a, b, c] : edges)
  {
    if (ufds.same_set(b, c))
      continue;
 
    ans.emplace_back(a, b, c);
    ufds.union_set(b, c);
  }
 
  return ans;
}
 
void solve()
{
  int n, m;
  cin >> n >> m;
  vector<tuple<ll, int, int>> edges(m);
  for (auto &[a, b, c] : edges) cin >> b >> c >> a;
 
  auto tree = kruskal(n, edges);
  if ((int)tree.size() != n - 1)
  {
    cout << "IMPOSSIBLE\n";
    return;
  }
 
  ll ans = 0;
  for (auto [x, a, b] : tree)
    ans += x;
 
  cout << ans << '\n';
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  solve();
 
  return 0;
}
