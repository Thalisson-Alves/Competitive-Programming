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
  vector<int> v(n);
  for (auto & x: v) cin >> x;
  int p = 0, s = 0;
  for (auto x : v) (x > 0 ? p++ : s++);

  int sum = 1;
  cout << sum++;
  for (int i = 1; i < p; i++)
    cout << ' ' << sum++;
  sum--;
  for (int i = 0; i < s; i++)
    cout << ' ' << --sum;
  cout<< '\n';

  if (s)
    cout << 1<< ' ' << 0;
  for (int i = 1; i < s; i++)
    cout <<' ' << 1<< ' ' << 0;

  sum = 1;
  for (int i = 0; i < p-s; i++)
    cout << ' ' << sum++;
  cout << '\n';
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

