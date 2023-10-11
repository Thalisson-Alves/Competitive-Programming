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
  string a, b;
  cin >> a >> b;
  cout << max(abs(a[0]-b[0]), abs(a[1]-b[1])) << '\n';
  while ((a[0] != b[0]) and (a[1] != b[1])) {
    cout << "RL"[a[0]>b[0]] << "UD"[a[1]>b[1]] << '\n';
    (a[0]>b[0]?b[0]++:a[0]++);
    (a[1]>b[1]?b[1]++:a[1]++);
  }
  while (a[0]!=b[0]) {
    cout << "RL"[a[0]>b[0]] << '\n';
    (a[0]>b[0]?b[0]++:a[0]++);
  }
  while (a[1]!=b[1]) {
    cout << "UD"[a[1]>b[1]] << '\n';
    (a[1]>b[1]?b[1]++:a[1]++);
  }
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
