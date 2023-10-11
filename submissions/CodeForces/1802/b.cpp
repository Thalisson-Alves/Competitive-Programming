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
  int n;
  cin >> n;
  int ans = 0, sum = 0, pets = 0, free2 = 0;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if (x == 1)
    {
      pets++;
      if (free2 > 0)
        free2--;
      else
        sum++;
    }
    else
    {
      int m = (pets-1) / 2;
      free2 += m;
      pets -= 2*m;
    }
    ans = max(ans, sum);
  }
  // ans = max(ans, pets + sum);
  cout << ans << '\n';
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

