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

#define sum(x) (x) * ((x)+1) * (2*(x)+1) / 6ll

  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ll cost = sum(i);
    ll mx = i * i;
    for (int j = 0; j < n-i; j++)
    {
      ll value = (n-j) * (i+j+1);
      cost += value;
      mx = max(mx, value);
    }
    ans = max(ans, cost - mx);
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
 
