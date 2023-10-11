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
  ull n, x;
  cin >> n >> x;
  auto original = n;

  ll ans = -1;
  for (ll i = 63; i >= 0; i--)
  {
    ull pos = 1ull << i;
    if ((n & pos) != (x & pos))
    {
      ans = i;
      break;
    }
  }

  n &= (-1ull << (ans + 1));
  if (n != x)
  {
    cout << "-1\n";
    return;
  }

  if (ans >= 0)
    n |= 1ll << (ans + 1);

  if (n < original)
    cout << "-1\n";
  else
    cout << n << '\n';
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

