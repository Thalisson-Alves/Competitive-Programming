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
  vector<int> v(3*n);
  vector<int> mp(n);
  vector<pair<int, int>> o;
  for (int i = 0; i < n*3; i++)
  {
    auto &x = v[i];
    cin >> x;
    x--;
    if (++mp[x] == 2)
      o.emplace_back(i, x);
  }
  sort(all(o));
  for (auto [_, x] : o)
    cout << x+1 << ' ';
  cout << '\n';
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

