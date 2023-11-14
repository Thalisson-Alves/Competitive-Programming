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

void solve()
{
  int n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  ll aoki = 0;
  for (auto &[a, b] : v) cin >> a >> b, aoki += a;
  sort(all(v), [](const auto &a, const auto &b) {
    return 2*a.first+a.second > 2*b.first+b.second;
  });
  ll takahashi = 0, res = 0;
  for (int i = 0; takahashi <= aoki and i < n; i++, res++) {
    takahashi += v[i].first + v[i].second;
    aoki -= v[i].first;
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
