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
  int n;
  cin >> n;
  vector<vector<string>> v(4, vector<string>(n));
  for (auto &x : v) for (auto &y : x) cin >> y;
  sort(all(v));

  int ans = INT_MAX;
  do
  {
    int cost = 0;
    for (int i = 0; i < 4; i++)
    {
      int color = ((i + 1) % 4) < 2;
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          cost += ((color + j + k) & 1) != (v[i][j][k] - '0');
    }
    ans = min({ans, cost, n*n*4-cost});
  }
  while (next_permutation(all(v)));
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

