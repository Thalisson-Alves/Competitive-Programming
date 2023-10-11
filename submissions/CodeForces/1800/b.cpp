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
  int n, k;
  cin >> n >> k;
  map<char, pair<int, int>> mp;
  for (int i = 0; i < n; i++)
  {
    char c;
    cin >> c;
    if (islower(c))
      mp[tolower(c)].first++;
    else
      mp[tolower(c)].second++;
  }
  ll ans = 0;
  for (auto [a, b] : mp)
  {
    auto l = min(b.first, b.second);
    auto r = max(b.first, b.second);

    auto rm = min(k, (r - l) / 2);
    ans += l + rm;
    k -= rm;
  }
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

