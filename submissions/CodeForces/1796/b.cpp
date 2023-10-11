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
  string a, b;
  cin >> a >> b;
  if (a[0] == b[0])
  {
    cout << "YES\n";
    cout << a[0] << "*\n";
    return;
  }
  if (a.back() == b.back())
  {
    cout << "YES\n";
    cout << "*" << a.back() << "\n";
    return;
  }
  for (int i = 0; i < (int)a.size(); i++)
  {
    int best = 0;
    for (int j = 0; j < (int)b.size(); j++)
    {
      int c = 0;
      while ((i + c < (int)a.size() and j + c < (int)b.size()) and a[i + c] == b[j + c])
        c++;

      best = max(best, c);
      if (best > 1) break;
    }
    if (best > 1)
    {
      cout << "YES\n";
      cout << "*" << a.substr(i, best) << "*\n";
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

