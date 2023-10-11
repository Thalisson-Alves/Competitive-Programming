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

ll MAX_N = 1e6;

void solve()
{
  int n;
  cin >> n;
  vector<int> has(1e6+1);
  int ans = 1;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;

    if (++has[x] > 1)
      ans = max(ans, x);
  }


  for (ll i = 2; i <= MAX_N; i++)
  {
    int cnt = 0;
    for (ll j = i; cnt < 2 and j <= MAX_N; j+=i)
      cnt += has[j];
    if (cnt >= 2)
      ans = max(ans, (int)i);
  }
  cout << ans << '\n';
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
