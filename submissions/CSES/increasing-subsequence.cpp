#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

int lis(const vector<int> &v)
{
  vector<int> res;
  for (auto x : v)
  {
    auto it = lower_bound(all(res), x);
    if (it == res.end())
      res.push_back(x);
    else
      *it = x;
  }
  return (int)res.size();
}

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;

  cout << lis(v) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}
