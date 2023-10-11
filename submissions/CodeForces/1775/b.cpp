#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'
#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

void solve()
{
  int n;
  cin >> n;

  unordered_map<int, int> cols;
  vector<vector<int>> mat(n);

  for (int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    mat[i].reserve(k);
    for (int j = 0; j < k; j++)
    {
      int x;
      cin >> x;
      cols[x]++;
      mat[i].push_back(x);
    }
  }

  for (int i = 0; i < n; i++)
  {
    bool ans = true;
    for (auto x : mat[i])
      if (cols[x] == 1)
        ans = false;
    if (ans)
    {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

