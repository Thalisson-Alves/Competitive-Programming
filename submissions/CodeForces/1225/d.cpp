#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> max_prime_dp(const int max_x=1e6) {
  vector<int> dp(max_x+1);
  dp[1] = 1;
  for (int i = 2; i <= max_x; i++) {
    if (dp[i]) continue;
    for (int j = i; j <= max_x; j+=i)
      dp[j] = i;
  }
  return dp;
}

void prime_factor_iter(int x, const vector<int> &max_prime, auto f) {
  assert(x < (int)max_prime.size());
  // void f(prime, cnt)
  static_assert(std::is_invocable_r_v<void, decltype(f), int, int>);
  int prev = max_prime[x], cnt = 1;
  do {
    x /= prev;
    int p = max_prime[x];
    if (p == prev) {
      ++cnt;
    } else {
      f(prev, cnt);
      cnt = 1;
      prev = p;
    }
  } while (x > 1);
}

void solve() {
  int n, k;
  cin >> n >> k;
  auto mp = max_prime_dp(1e5);
  map<vector<pair<int, int>>, int> cnt;
  ll res = 0;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    vector<pair<int, int>> fat, inv;
    prime_factor_iter(x, mp, [&](int p, int c) {
      int d = c%k;
      if (!d) return;
      fat.emplace_back(p, d);
      inv.emplace_back(p, (k-d)%k);
    });
    res += cnt[inv];
    cnt[fat]++;
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
