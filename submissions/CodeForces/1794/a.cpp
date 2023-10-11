#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'
#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<ll, ll>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n;
  cin >> n;
  string a, b;
  for (int i = 0; i < 2*n-2; i++)
  {
    string x;
    cin >> x;
    if (x.size() > a.size())
      a = x;
    else if (x.size() > b.size())
      b = x;
  }
  string s;
  if (a.substr(1) == b.substr(0, n-2))
    s = a + b.back();
  else
    s = b + a.back();

  string ans = "YES";
  for (int i = 0; i < n / 2; i++)
    if (s[i] != s[n-1-i])
      ans = "NO";
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

