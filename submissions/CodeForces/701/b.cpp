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
ll oo = 1e18;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  ll n, m;
  cin >> n >> m;
  set<ll> xs, ys;
  for (ll i = 0; i < m; i++)
  {
    ll x, y;
    cin >> x >> y;
    xs.insert(x);
    ys.insert(y);

    cout << n*n-xs.size()*n-ys.size()*(n-xs.size()) << " \n"[i == m-1];
  }
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

