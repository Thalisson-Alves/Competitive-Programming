#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

ll dist(pair<ll, ll> &a, pair<ll, ll> &b)
{
  return abs(a.first - b.first)  + abs(a.second-b.second);
}

void solve()
{
  int n, k, a, b;
  cin >> n >> k >> a >> b;
  vector<pair<ll, ll>> ps(n);
  for (auto &[x,y]:ps)cin >> x>>y;

  --a, --b;
  int ca = -1, cb = -1;
  for (int i = 0; i < k; i++)
  {
    if (ca == -1 or dist(ps[a],ps[ca])>dist(ps[a],ps[i]))
      ca = i;
    if (cb == -1 or dist(ps[b],ps[cb])>dist(ps[b],ps[i]))
      cb = i;
  }

  ll ans = dist(ps[a], ps[b]);
  dbg(ans, a, b, ca, cb);
  if (ca != -1) ans = min(ans, dist(ps[a], ps[ca]) + dist(ps[cb], ps[b]));
  cout << ans << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}
