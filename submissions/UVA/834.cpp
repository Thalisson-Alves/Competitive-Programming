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
  int n, d;
  while (cin >> n >> d)
  {
    vector<int> ans;
    while (d)
    {
      ans.push_back(n / d);

      auto tmp = d;
      d = n % d;
      n = tmp;
    }

    cout << "[" << ans[0] << ";" << ans[1];
    for (int i = 2; i < (int)ans.size(); i++)
      cout << "," << ans[i];
    cout << "]\n";
  }
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

