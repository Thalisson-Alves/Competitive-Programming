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

void dfs(int n, int a, int b, int c)
{
  if (!n) return;
  dfs(n-1, a, c, b);
  cout << a << ' ' << c << '\n';
  dfs(n-1, b, a, c);
}

void solve()
{
  int n;
  cin >> n;
  cout << (1<<n)-1 << '\n';
  dfs(n, 1, 2, 3);
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
