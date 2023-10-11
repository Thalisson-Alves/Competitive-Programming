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
  vector<pair<ll, int>> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(all(a));
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
    {
      auto it = lower_bound(a.begin() + j + 1, a.end(), make_pair(k - (a[i].first + a[j].first), -1));
      if (it != a.end() and it->first + a[i].first + a[j].first == k)
      {
        cout << a[i].second + 1 << ' ' << a[j].second + 1 << ' ' << it->second + 1 << '\n';
        return;
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

