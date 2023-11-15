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
  int n;
  cin >> n;
  vector<string> g(3);
  for (auto &s : g) cin >> s, s = s + s + s;
  vector<vector<vector<int>>> mt(3, vector<vector<int>>(10));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < (int)g[i].size(); j++)
      mt[i][g[i][j]-'0'].push_back(j);
  }
  int ans = INT_MAX;
  for (int i = 0; i < 10; i++) {
    dbg(i);
    for (auto j : mt[0][i]) {
      for (auto k : mt[1][i]) {
        for (auto l : mt[2][i]) {
          if (set<int>{j, k, l}.size() == 3)
            ans = min(ans, max({j, k, l}));
        }
      }
    }
  }
  cout << (ans == INT_MAX ? -1 : ans) << '\n';
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
