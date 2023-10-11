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
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  ll n;
  cin >> n;
  ll sm = 1e9, mn = 1e9, ans = 0;
  while (n--)
  {
    ll m;
    cin>>m;
    vector<ll> a(m);
    for (auto &x : a)
      cin >> x;
 
    sort(all(a));
 
    ans += a[1];
    mn = min(mn, a[0]);
    sm = min(sm, a[1]);
  }
 
  cout << ans - (sm - mn) << '\n';
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
 
