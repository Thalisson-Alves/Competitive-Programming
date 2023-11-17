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

vector<ll> divisors(ll n) {
  vector<ll> d;
  for (ll i = 1; i*i <= n; i++) if (n%i == 0) {
    d.push_back(i);
    if (n/i != i) d.push_back(n/i);
  }
  return d;
}

void solve()
{
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;
  ll res = 0;
  for (auto k : divisors(n)) {
    ll mx = -1, mn = LLONG_MAX;
    for (int i = 0; i < n/k; i++) {
      ll acc = 0;
      for (int j = 0; j < k; j++) {
        acc += v[i*k+j];
      }
      mx = max(mx, acc);
      mn = min(mn, acc);
    }
    res = max(res, mx - mn);
  }
  cout << res << '\n';
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
