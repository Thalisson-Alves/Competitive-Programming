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
  int n;
  cin >> n;
  vector<ll> a(n);
  ll mx = 0, mn = LLONG_MAX;
  for (auto &x : a) cin >> x, mx = max(mx, x), mn = min(mn, x);
  ll res = 0;
  vector<ll> op;
  while (mn < mx) {
    res++;
    ll dif = LLONG_MAX, best = -1;
    for (ll d = 0; d < 4; d++) {
      if ((mx + d) / 2 - (mn + d) / 2 < dif) {
        dif = (mx + d) / 2 - (mn + d) / 2;
        best = d;
      }
    }
    assert(best != -1);
    mn = (mn + best) / 2;
    mx = (mx + best) / 2;
    op.push_back(best);
  }
  cout << res << '\n';
  if (res <= n) {
    for (int i = 0; i < res; i++)
      cout << op[i] << " \n"[i == res-1];
  }
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
