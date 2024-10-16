#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T> vector<T> divisors(T n) {
  vector<T> d;
  for (T i = 1; (ll)i*i <= n; i++) if (n%i == 0) {
    d.push_back(i);
    if (n/i != i) d.push_back(n/i);
  }
  return d;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  sort(begin(a), end(a));
  vector<int> dp(2e5+1);
  int res = n;
  for (auto x : a) {
    int best = 0;
    for (auto d : divisors(x))
      best = max(best, dp[d] + 1);
    dp[x] = best;
    res = min(res, n-best);
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
