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

void solve()
{
  ll w, h;
  cin >> w >> h;

  ll n;
  cin >> n;

  vector<pair<ll, ll>> v(n);
  for (auto &[x, y] : v) cin >> x >> y;

  ll an;
  cin >> an;
  vector<ll> va(an);
  for (auto &x : va) cin >> x;

  ll bn;
  cin >> bn;
  vector<ll> vb(bn);
  for (auto &x : vb) cin >> x;

  map<pair<ll, ll>, ll> ans;
  for (auto [x, y] : v)
  {
    auto r = upper_bound(all(va), x) - va.begin();
    auto u = upper_bound(all(vb), y) - vb.begin();

    ans[make_pair(r, u)]++;
  }

  ll mn = oo, mx = -1;
  for (auto [_, x] : ans)
  {
    mn = min(mn, x);
    mx = max(mx, x);
  }

  if ((ll)ans.size() < (an+1)*(bn+1))
    mn = 0;

  cout << mn << ' ' << mx << '\n';
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

