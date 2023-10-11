#include <bits/stdc++.h>
#include <string>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'
#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  string s;
  cin >> s;
  ll n = s.size();
  if (s[0] == s[1])
  {
    cout << s[0] << ' ' << s[1] << ' ' << s.substr(2) << '\n';
    return;
  }
  if (s[n-1] == s[n-2])
  {
    cout << s.substr(0, n-2) << ' ' << s[n-2] << ' ' << s[n-1] << '\n';
    return;
  }
  string b;
  b += s[1];
  for (int i = 2; s[i] == b.back(); i++)
    b += s[i];
  cout << s[0] << ' ' << b << ' ' << s.substr(b.size() + 1) << '\n';
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

