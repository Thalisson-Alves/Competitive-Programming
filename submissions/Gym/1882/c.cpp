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

void solve()
{
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;
  ll res = 0;
  vector<ll> even(n+1);
  vector<char> got(n);
  for (int i = n-1; ~i; --i) {
    even[i] = even[i+1];
    if ((i&1) and v[i] > 0)
      even[i] += v[i];

    if (!(i&1) and v[i] >= 0) {
      res += v[i] + even[i];
      even[i] = 0;
      got[i] = 1;
    }
  }

  ll ans = res;
  for (int i = 0; i < n; i++) {
    if (got[i]) break;
    auto value = res+(i&1 ? even[i+1] : v[i]+even[i+1]);
    ans = max(ans, value);
    dbg(value);
  }

  dbg(even, res, ans);
  cout << ans << '\n';
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}

