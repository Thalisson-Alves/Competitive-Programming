#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

auto best(const vector<int> &p, int i, int dir)
{
  if (i+dir >= (int)p.size() or i+dir < 0)
    return INT_MAX;

  auto ans = abs(p[i] - p[i+dir]) + 1;
  for (int j = i+2*dir; j >= 0 and j < (int)p.size(); j+=dir)
  {
    auto value = abs(p[i]-p[j]) + abs(i - j);
    if (value < ans)
      ans = value;
    else if (abs(i - j) >= ans)
      break;
  }
  return ans;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &x : p) cin >> x;
  for (int i = 0; i < n; i++)
    cout << min(best(p, i, 1), best(p, i, -1)) << '\n';
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

