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

ll lower_than(const vector<set<ll>> &g, ll i, int mx, vector<ll> &lower)
{
  if (mx < 0)
    return -10;

  if (lower[i] >= 0)
    return lower[i];

  ll ans = 0;
  // cerr << df(i) << dfn(g[i].size());
  for (auto &x : g[i])
  {
    lower[x] = lower_than(g, x, mx - 1, lower);
    ans = max(lower[x] + 1, ans);
  }
  return ans;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<set<ll>> g(n);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    g[x-1].insert(y-1);
  }

  vector<ll> lower(n, -1);
  for (int i = 0; i < n; i++)
    lower_than(g, i, n, lower);

  set<ll> st(all(lower));
  if ((int)st.size() != n || st.count(-10))
  {
    cout << "No\n";
    return;
  }

  cout << "Yes\n";
  for (int i = 0; i < n; i++)
    cout << (n - (lower[i] == -1 ? n-1 : lower[i])) << " \n"[i == n-1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

