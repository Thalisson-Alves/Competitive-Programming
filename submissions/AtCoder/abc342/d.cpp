#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

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
  int n;
  cin >> n;
  ll res = 0;
  map<vector<ll>, ll> mp;
  ll zeros = 0;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (x == 0) {
      res += n - ++zeros;
    } else {
      vector<ll> f;
      for (auto [a, b] : factors(x))
        if (b&1) f.push_back(a);
      res += mp[f]++;
    }
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
