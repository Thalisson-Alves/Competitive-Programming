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

bool ok(const vector<ll> &v, ll mid, const ll m) {
  ll ans = 0;
  for (auto x : v) {
    if (ans >= m - mid / x)
      return true;
    ans += mid / x;
  }
  return false;
}

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;
  ll l = 1, r = 1e18;
  while (l <= r){
    auto mid = l + (r-l) / 2;
    if (ok(v, mid, m))
      r = mid-1;
    else
      l = mid+1;
  }
  cout << l << '\n';
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
