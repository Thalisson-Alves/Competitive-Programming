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
  ll n, k;
  cin >> n >> k;
  string s, t;
  cin >> s >> t;
  vector<int> hs(30), ht(30);
  for (auto c : s)
    hs[c - 'a']++;
  for (auto c : t)
    ht[c - 'a']++;
  if (hs != ht)
  {
    cout << "NO\n";
    return;
  }

  ll cant = 2ll*k-n;
  if (cant <= 0)
  {
    cout << "YES\n";
    return;
  }

  string ans = "YES";
  for (ll i = 0, start = max((n - cant) / 2, 0ll); i < cant and i + start < n; i++)
    if (s[i + start] != t[i + start])
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

