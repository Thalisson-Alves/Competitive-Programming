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

void solve()
{
  ll n, m, d;
  cin >> n >> m >> d;

  set<ll> a, b;
  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    a.insert(x);
  }

  for (int i = 0; i < m; i++)
  {
    ll x;
    cin >> x;
    b.insert(x);
  }

  ll ans = -1;
  for (auto x : a)
  {
    auto it = b.upper_bound(x + d);
    if (it == b.begin())
      continue;

    it = prev(it);
    if (abs(*it - x) > d)
      continue;

    ans = max(ans, *it + x);
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

