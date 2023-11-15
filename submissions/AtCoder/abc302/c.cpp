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

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<string> v(n);

  for (auto &x : v) cin >> x;
  sort(all(v));

  do
  {
    bool ans = true;
    for (int i = 1; i < n; i++)
    {
      int dist = 0;
      for (int j = 0; j < m; j++)
        dist += v[i-1][j] != v[i][j];

      if (dist != 1)
      {
        ans = false;
        break;
      }
    }

    if (ans)
    {
      cout << "Yes\n";
      return;
    }
  } while (next_permutation(all(v)));

  cout << "No\n";
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

