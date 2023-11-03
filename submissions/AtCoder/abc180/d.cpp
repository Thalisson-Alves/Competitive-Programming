#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  ll x, y, a, b;
  cin >> x >> y >> a >> b;
  ll res = 0;
  for (ll k = 0; (y-x)>=b; k++, x *= a) {
    res = max(res, k + (y-x+b-1)/b-1);
    if (x >= LLONG_MAX / a)
      break;
  }
  cout << res << '\n';
}

int32_t main()
{
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
