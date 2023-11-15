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

void prop(const vector<vector<ll>> &g, int cur, vector<ll> &lazy)
{
  for (auto x : g[cur])
  {
    lazy[x] = max(lazy[x], lazy[cur] - 1);
    prop(g, (int)x, lazy);
  }
}

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n);
  for (int i = 1; i < n; i++)
  {
    int x;
    cin >> x;
    g[--x].push_back(i);
  }

  vector<ll> lazy(n, 0);
  while (m--)
  {
    ll a, b;
    cin >> a >> b;
    a--;

    lazy[a] = max(lazy[a], b + 1);
  }

  prop(g, 0, lazy);
  ll ans = 0;
  dbg(lazy);
  for (auto x : lazy) ans += x > 0;

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

