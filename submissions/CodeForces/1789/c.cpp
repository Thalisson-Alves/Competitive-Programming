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
  int n, m;
  cin >> n >> m;
  vector<int> v(n), count(n + m + 1), appear(n + m + 1);
  for (auto &x : v) cin >> x, appear[x] = 0;
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;

    count[v[x-1]] += i - appear[v[x-1]] + 1;
    v[x-1] = y;
    appear[y] = i + 1;
  }
  for (auto i : v)
    count[i] += m + 1 - appear[i];

  ll ans = 0;
  for (auto x : count)
  {
    ll p = m + 1 - x;
    ans += 1LL * x * (x - 1) / 2 + x * p;
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

