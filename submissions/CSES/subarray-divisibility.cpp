#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> ps(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> ps[i];
    ps[i] = (ps[i] + ps[i-1]) % n;
    if (ps[i] < 0) ps[i] += n;
  }
  ll res = 0;
  vector<int> mp(n, -1), cnt(n);
  for (int i = n; ~i; --i) {
    res += cnt[ps[i]]++;
    mp[ps[i]] = i;
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
