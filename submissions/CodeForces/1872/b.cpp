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
  vector<pair<int, int>> v(n);
  for (auto &[a,b]: v) cin >> a >> b;
  sort(all(v));
  int ans = v[0].first, moves = (v[0].second - 1) / 2;
  for (int i = 1; i < n; i++)
  {
    dbg(ans, moves);
    if (ans + moves >= v[i].first)
    {
      moves = min(moves - (v[i].first - ans), (v[i].second - 1) / 2);
      ans = v[i].first;
    }
  }
  ans += moves;
  cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}
