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
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

map<ll, ll> factors(ll n)
{
  map<ll, ll> ans;
  for (ll i = 2; i*i <= n; i++)
  {
    ll count = 0;
    for (; n%i==0; count++, n/=i);
    if (count)
      ans[i] = count;
  }
  if (n > 1) ans[n]++;
  return ans;
}

void solve()
{
  ll a, b;
  cin >> a >> b;
  auto fa = factors(a);
  auto fb = factors(b);

  ll ans = 1;
  for (auto [k, _] : fa) {
    if (fb[k]) ans++;
  }
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

