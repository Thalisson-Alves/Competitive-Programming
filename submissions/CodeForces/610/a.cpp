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
  ll n;
  cin >> n;
  if (n & 1) cout << 0 << '\n';
  else cout << (n + 3) / 4 - 1 << '\n';
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

