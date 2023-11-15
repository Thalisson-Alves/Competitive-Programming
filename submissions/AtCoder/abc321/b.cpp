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
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> v(n-1);
  for (auto &x : v) cin >> x;
  sort(all(v));
  ll sum = accumulate(all(v), 0ll);
  if (sum - v[0] < m) {
    cout << "-1\n";
  } else if (sum - v.back() >= m) {
    cout << "0\n";
  } else {
    cout << max(0ll, m - (sum - v.back() - v[0])) << '\n';
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

