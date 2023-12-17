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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a) cin >> x >> y;

  auto can = [&a](int k) {
    int mn = 0, mx = 0;
    for (auto [l, r] : a) {
      if (mx + k < l) return false;
      if (mn - k > r) return false;

      if (mn <= l) {
        mn = l;
      } else {
        mn = max(mn - k, l);
      }

      if (mx <= r) {
        mx = min(mx + k, r);
      } else {
        mx = r;
      }
    }

    return true;
  };

  int l = 0, r = 1e9+1;
  while (l <= r) {
    auto mid = midpoint(l, r);
    if (can(mid)) r = mid - 1;
    else l = mid + 1;
  }
  cout << l << '\n';
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
