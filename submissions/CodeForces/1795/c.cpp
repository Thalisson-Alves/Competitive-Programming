#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'
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
  vector<ll> a(n), b(n), ans(n + 1), d(n+1);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  vector<ll> ps(n+1);
  for (int i = 0; i < n; i++)
    ps[i+1] = ps[i] + b[i];

  for (int i = 0; i < n; i++)
  {
    auto it = upper_bound(all(ps), a[i] + ps[i]) - ps.begin() - 1;
    d[i]++;
    d[it]--;
    ans[it] += a[i] - (ps[it] - ps[i]);
  }
  ll sum = 0;
  for (int i = 0; i < n; i++)
    sum += d[i], ans[i] += sum * b[i];

  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n-1];
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

