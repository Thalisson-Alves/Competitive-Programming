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
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (auto &s : g) cin >> s;

  vector<int> ans(min(n, m));
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (g[i][j] == '#' and g[i-1][j-1] == '#' and g[i-1][j+1] == '#') {
        int sum = 0;
        for (int k = 1; i-k >= 0 and j-k >= 0 and g[i-k][j-k] == '#'; k++)
          sum++;
        ans[sum-1]++;
      }
    }
  }

  for (auto x : ans) cout << x << ' ';
  cout << '\n';
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
