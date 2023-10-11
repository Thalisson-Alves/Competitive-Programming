#include <bits/stdc++.h>
#include <memory>
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
  string s;
  cin >> s;
  string ans;
  for (ll i = n-1, carry = 0; ~i; i--)
  {
    ans.push_back(('9' - s[i] - carry + 2) % 10 + '0');
    carry = (carry and s[i] > '0') or (s[i] > '1');
  }
  reverse(all(ans));
  if (ans[0] == '0')
  {
    for (ll i = n-1, carry = 0; ~i; i--)
    {
      auto prev = ans[i];
      ans[i] = (ans[i] - '0' + 1 + carry) % 10 + '0';
      carry = prev > ans[i];
    }
    if (ans[0] == '0') ans[0] = '1';
  }

  cout << ans << "\n";
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

