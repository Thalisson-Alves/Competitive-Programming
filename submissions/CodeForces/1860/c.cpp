#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  ll ans = 0, mn = a[0], best = 1e9;
  for (int i = 0; i < n; i++)
  {
    if (a[i] > mn and a[i] < best)
    {
      ans++;
      best = a[i];
    }
    else
      mn = min(mn , a[i]);
  }

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
