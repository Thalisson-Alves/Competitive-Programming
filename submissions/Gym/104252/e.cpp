#include <bits/stdc++.h>
#include <memory>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vector<pair<int, int>> possibilities(int e, int k)
{
  vector<pair<int, int>> ans{{0, 0}};
  for (int i = 0; i <= max(e, 4); i++)
  {
    for (int j = e - i; j > max(i, e - i - 4); j--)
    {
      if (i == k or j == k) continue;
      ans.emplace_back(j, i);
    }
  }
  return ans;
}

void solve()
{
  int n, k, e;
  cin >> n >> k >> e;

  auto left = possibilities(e, k);
  auto right = possibilities(n - k - e, k);
  int ans = INT_MAX;
  for (auto [a, b] : left)
  {
    for (auto [c, d] : right)
    {
      if ((a and (a == c or a == d)) or (b and (b == c or b == d))) continue;

      ans = min(ans, e-a-b + n-k-e-c-d);
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
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

