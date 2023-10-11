#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n';
#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n;
  cin >> n;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    mp[x&1].push_back(i+1);
  }
  if (mp[1].empty() or (mp[1].size() == 2 and mp[0].size() == 1))
  {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  if (mp[1].size() >= 3)
  {
    for (auto i = 0; i < 3; i++)
      cout << mp[1][i] << " \n"[i == 2];
  }
  else
  {
    cout << mp[0][0] << ' ' << mp[0][1] << ' ' << mp[1][0] << '\n';
  }
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

