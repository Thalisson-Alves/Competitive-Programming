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
  ll n, p, l, t;
  cin >> n >> p >> l >> t;

  ll weeks = (n + 6) / 7;
  ll lo = 0, hi = n;
  while (lo <= hi) {
    auto mid = midpoint(lo, hi);
    if (l * mid >= p - min(weeks, 2 * mid) * t)
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  cout << (n - lo) << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
