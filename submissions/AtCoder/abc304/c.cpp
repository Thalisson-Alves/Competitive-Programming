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

double point_dist(pair<int, int> &a, pair<int, int> &b)
{
  return hypot(a.first - b.first, b.second - a.second);
}

void solve()
{
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> v(n);
  for (auto &[x, y] : v) cin >> x >> y;

  queue<pair<int, int>> q;
  q.emplace(v[0]);

  vector<char> vis(n);
  vis[0] = true;

  vector<char> inf(n);
  inf[0] = 1;

  while (not q.empty())
  {
    auto top = q.front(); q.pop();
    for (int i = 0; i < n; i++)
    {
      if (not vis[i] and point_dist(top, v[i]) <= d)
      {
        q.emplace(v[i]);
        vis[i] = 1;
        inf[i] = 1;
      }
    }
  }

  for (int i = 0; i < n; i++)
    cout << (inf[i] ? "Yes" : "No") << '\n';
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

