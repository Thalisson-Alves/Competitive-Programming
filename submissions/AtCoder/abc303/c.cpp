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
  int n, m, h, k;
  cin >> n >> m >> h >> k;
  string s;
  cin >> s;
  set<pair<int, int>> ps;
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    ps.emplace(x, y);
  }

  pair<int, int> pos;
  for (auto x : s)
  {
    switch (x)
    {
    case 'R':
      pos.first += 1;
      break;
    case 'L':
      pos.first -= 1;
      break;
    case 'D':
      pos.second -= 1;
      break;
    case 'U':
      pos.second += 1;
      break;
    }

    if (--h < 0)
    {
      cout << "No\n";
      return;
    }

    if (ps.count(pos) and h < k)
    {
      h = k;
      ps.erase(pos);
    }

  }
  cout << "Yes\n";
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

