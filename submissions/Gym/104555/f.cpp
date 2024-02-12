#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  int d, c, r;
  cin >> d >> c >> r;
  vector<int> v(c);
  for (auto &x : v) cin >> x;
  int res = r;
  while (r--) {
    int x;
    cin >> x;
    d += x;
  }

  for (auto x : v) {
    if (x > d) break;
    d -= x;
    res++;
  }

  cout << res << '\n';
}

int32_t main() {
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
