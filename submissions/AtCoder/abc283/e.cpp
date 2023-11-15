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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  for (auto &row : mat)
    for (auto &x : row) cin >> x;

  vector<int> iso(n), cant(n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      bool connected = false;
      bool ev = true, dh = true;
      if (i+1<n)
      {
        connected |= mat[i+1][j] == mat[i][j];
        ev &= mat[i+1][j] == mat[i][j];
      }
      if (j+1<n)
      {
        connected |= mat[i][j+1] == mat[i][j];
        dh &= mat[i][j+1] != mat[i][j];
      }
      if (i>0)
      {
        connected |= mat[i-1][j] == mat[i][j];
        ev &= mat[i-1][j] == mat[i][j];
      }
      if (j>0)
      {
        connected |= mat[i][j-1] == mat[i][j];
        dh &= mat[i][j-1] != mat[i][j];
      }

      if (not connected)
        iso[i] = true;
      if (ev and dh)
        cant[i] = true;
    }
  }

  auto ans = 0;
  vector<int> used(n);
  for (int i = 0; i < n; i++)
  {
    if (not iso[i]) continue;
    int to_use = 42, ok = false;
    for (int j = 1; j >= -1; j--)
    {
      if (i+j < 0 or i+j >= n) continue;
      if (used[j+i])
        ok = true;
      if (to_use == 42 and cant[i+j] == 0)
        to_use = i+j;
    }

    if (ok)
      continue;

    if (to_use == 42)
    {
      ans = -1;
      break;
    }

    used[to_use] = true;
    ans++;
  }
  cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

