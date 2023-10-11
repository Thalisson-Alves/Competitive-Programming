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
  int n = 10;
  vector<string> v(n);
  for (auto &x : v) cin >> x;
  ll ans = 0;
  for (ll i =0 ; i< n ; i++) {
    for (ll j = 0; j < n; j++) {
      if (v[i][j] != 'X') continue;
      ans += min({i+1, j+1, n-i, n-j});
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
