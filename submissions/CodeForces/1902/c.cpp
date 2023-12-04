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
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  if (n == 1) {
    cout << "1\n";
    return;
  }
  sort(all(a));
  ll g = a.back() - a[0];
  for (int i = 1; i < n-1; i++) {
    g = gcd(g, a.back() - a[i]);
  }

  ll res = 0;
  for (int i = 0; i < n; i++) {
    res += (a.back()-a[i]) / g;
  }
  ll cnt = 0, i = a.back();
  for (; binary_search(a.begin(), a.end(), i); i -= g, cnt++);
  cout << res + cnt << '\n';
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
