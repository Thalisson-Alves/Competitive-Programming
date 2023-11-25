#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> xs(n), ys(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i] >> ys[i];
  }
  sort(all(xs));
  sort(all(ys));

  vector<ll> px(n), py(n);
  partial_sum(all(xs), px.begin());
  partial_sum(all(ys), py.begin());

  auto cost = [&](int side) -> ll {
    ll rx = LLONG_MAX, ry = LLONG_MAX;
    for (int i = 0; i < n; i++) {
      {
        ll c = xs[i] * (i+1) - px[i];
        auto pos = (int)(upper_bound(all(xs), xs[i]+side) - xs.begin()) - 1;
        c += (px.back()-px[pos]) - (n-pos-1)*(xs[i] + side);
        rx = min(rx, c);
      }
      {
        ll c = (px.back() - px[i]) - xs[i] * (n-1-i);
        auto pos = (int)(lower_bound(all(xs), xs[i]-side) - xs.begin()) - 1;
        if (~pos)
          c += (xs[i] - side) * (pos+1) - px[pos];
        rx = min(rx, c);
      }
      {
        ll c = ys[i] * (i+1) - py[i];
        auto pos = (int)(upper_bound(all(ys), ys[i]+side) - ys.begin()) - 1;
        c += (py.back()-py[pos]) - (n-pos-1)*(ys[i] + side);
        ry = min(ry, c);
      }
      {
        ll c = (py.back() - py[i]) - ys[i] * (n-1-i);
        auto pos = (int)(lower_bound(all(ys), ys[i]-side) - ys.begin()) - 1;
        if (~pos)
          c += (ys[i] - side) * (pos+1) - py[pos];
        ry = min(ry, c);
      }
    }
    return rx + ry;
  };

  int l = 0, r = INT_MAX;
  while (l <= r) {
    auto mid = midpoint(l, r);
    if (cost(mid) <= k)
      r = mid-1;
    else
      l = mid+1;
  }
  cout << l << '\n';
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
