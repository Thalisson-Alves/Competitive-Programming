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
  int n, h;
  cin >> n >> h;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  sort(all(v));
  queue<tuple<ll, ll, int, int>> q;
  q.emplace(h, 0, 2, 1);
  ll ans = 0;
  while (not q.empty())
  {
    auto [p, k, g, b] = q.front();
    q.pop();
    ans = max(ans, k);

    if (k == n) break;
    if (v[k] < p)
      q.emplace(p + v[k] / 2, k + 1, g, b);
    else
    {
      if (g)
        q.emplace(p * 2, k, g-1, b);
      if (b)
        q.emplace(p * 3, k, g, b-1);
    }
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

