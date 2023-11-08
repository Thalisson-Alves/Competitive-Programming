#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n), suf(n+1);
  for (auto &x : a) cin >> x;
  sort(all(a));
  for (int i = n-1; ~i; --i)
    suf[i] = suf[i+1] + a[i];

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs(a[i] * (n-i-1) - suf[i+1]);
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
