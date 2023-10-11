#include <bits/stdc++.h>
#include <string>
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
  ll n, m;
  cin >> n >> m;
  ll dim = 4;
  while (dim <= max(n, m))
    dim *= 4;

  // ll dim = max(n-(n%4)+4, m-(m%4)+4);
  vector<vector<ull>> mat(dim, vector<ull>(dim));
  ull ans = 0;
  for (ll i = 0; i < dim; i++)
  {
    for (ll j = 0; j < dim; j++)
      mat[i][j] = ans++;
  }
  cout << n * m << '\n';
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < m; j++)
      cout << mat[i][j] << " \n"[j==m-1];
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

