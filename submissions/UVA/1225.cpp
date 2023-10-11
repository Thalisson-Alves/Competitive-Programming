#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve()
{
  int n;
  cin >> n;
  vector<int> ans(10);
  for (int i = 1; i <= n; i++)
  {
    for (int x = i; x; x /= 10)
      ans[x%10]++;
  }

  for (int i = 0; i < 10; i++)
    cout << ans[i] << " \n"[i == 9];
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

