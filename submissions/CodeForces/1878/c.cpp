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
  ll n, k, x;
  cin >> n >> k >> x;
#define SUM(x) ((x)*((x)+1)/2)
  dbg(SUM(k), SUM(n)-SUM(n-k), x);
  if (SUM(k) > x) {
    cout << "NO\n";
    return;
  }
  if (SUM(n)- SUM(n-k) < x) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
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

