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

ll dfs(const vector<pair<ll, ll>> &ps, ll stop, ll u, vector<vector<ll>> &memo)
{
  if (stop >= (int)ps.size()) return 0;
  ll mod = memo[0].size();
  ll fa = u % mod;
  if (memo[stop][fa]) return memo[stop][fa];

  ll wait = (ps[stop].first - (u%ps[stop].first))%ps[stop].first;
  return memo[stop][fa] = (wait+ps[stop].second + dfs(ps, stop+1, wait+u+ps[stop].second, memo));
}

void solve()
{
  ll n, x, y;
  cin >> n >> x >> y;
  vector<pair<ll, ll>> ps(n-1);
  ll asdf = 1;
  for (auto &[a, b] : ps) cin >> a >> b, asdf = lcm(asdf, a);

  vector<vector<ll>> dp(n-1, vector<ll>(asdf));

  int q;
  cin >> q;
  while(q--)
  {
    ll t;
    cin >> t;

    cout << dfs(ps, 0, t + x, dp) + y + x + t << '\n';
  }
  dbg(dp);
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
