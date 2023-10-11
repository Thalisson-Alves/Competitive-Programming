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
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  set<int> st(all(v));
  int ans = -1;
  for(auto x : st)
  {
    bool ok = true;
    for (auto y : st)
    {
      if (x == y) continue;
      if (x % y == 0) ok = false;
    }

    if (ok)
    {
      ans = x;
      break;
    }
  }

  vector<int> b, c;
  for (int i =0; i < n; i++)
  {
    if (v[i] == ans) b.push_back(v[i]);
    else c.push_back(v[i]);
  }

  dbg(v);

  if (b.empty() or c.empty())
  {
    cout << "-1\n";
    return;
  }

  cout << b.size() << ' ' << c.size() << '\n';
  for (auto x : b) cout << x << ' ';
  cout << '\n';
  for (auto x : c) cout << x << ' ';
  cout << '\n';
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
 
