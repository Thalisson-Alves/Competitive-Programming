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

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  map<ll, vector<pair<int, int>>> mp;
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
      mp[a[i]+a[j]].emplace_back(i, j);

  for (auto [x, y] : mp)
  {
    for (auto p : y)
    {
      for (auto q : mp[k-x])
      {
        if (set<int>{p.first,p.second,q.first,q.second}.size() == 4)
        {
          cout << p.first + 1 << ' ' << p.second + 1 << ' ' << q.first + 1 << ' ' << q.second + 1 << '\n';
          return;
        }
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}

int main()
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

