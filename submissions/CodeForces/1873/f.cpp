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

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), h(n);
  for (auto &x : a) cin >> x;
  for (auto &x : h) cin >> x;
  vector<ll> pref(n+1);
  for (int i = 0; i < n; i++)
    pref[i+1] = pref[i] + a[i];
  int ans = 0;
  for (int l = 0, r = 0; r < n;) {
    while (r+1 < n and h[r] % h[r+1] == 0 and pref[r+2] - pref[l] <= k) r++;
    if (pref[r+1] - pref[l] <= k)
      ans = max(ans, r - l + 1);

    if (r >= n-1) break;
    if (h[r] % h[r+1]) {
      l = ++r;
    } else {
      auto  pl = l;
      while (l <= r and pref[r+1] - pref[l] > k) l++;
      if (pl == l) l++;
      r = max(l, r);
    }
  }
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
