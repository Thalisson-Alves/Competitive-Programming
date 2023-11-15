#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'
#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n+10);
  v[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < i; j++)
      cout << v[j] << " \n"[j == i-1];

    v[i] = 1;
    for (int j = i-1; j > 0; j--)
      v[j] += v[j-1];
  }
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

