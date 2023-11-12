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

vector<ll> subset_sum(const vector<ll> &v) {
  int n = (int)v.size();
  vector<ll> res;
  for (int i = 0; i < (1ll << n); i++) {
    ll sum = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1ll << j))
        sum += v[j];
    }
    res.push_back(sum);
  }
  sort(all(res));
  return res;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<ll> a(n/2), b(n-n/2);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  auto sa = subset_sum(a);
  auto sb = subset_sum(b);

  ll ans = 0;
  for (auto x : sa) {
    auto [l, r] = equal_range(all(sb), m-x);
    ans += r - l;
  }

  cout << ans << '\n';
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
