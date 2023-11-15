#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

set<int> digits(int x) {
  set<int> res;
  while (x) {
    res.insert(x%10);
    x /= 10;
  }
  return res;
}

void solve()
{
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    auto si = digits(i+1);
    if (si.size() > 1) continue;
    for (int j = 1; j <= d; j++) {
      res += si == digits(j);
      dbg(i+1, j, res);
    }
  }
  cout << res << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
