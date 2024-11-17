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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  constexpr int mxn = 1e6;
  auto mp = max_prime_dp(mxn);
  vector<ll> dp(mxn+1);
  constexpr ll mod = 998244353;
  ll last = 0;
  for (int i = n-1; ~i; --i) {
    ll res = i==n-1;
    vector<int> primes;
    prime_factor_iter(a[i], mp, [&](int p, int) { primes.push_back(p); });
    ll mul;
    for (int msk = 1; msk < 1 << (int)primes.size(); msk++) {
      mul = 1;
      for (int j = 0; j < (int)primes.size(); j++) if (msk>>j&1) {
        mul *= primes[j];
      }
      (res += (popcount(1u*msk)&1 ? dp[mul] : mod-dp[mul])) %= mod;
    }
    for (int msk = 1; msk < 1 << (int)primes.size(); msk++) {
      mul = 1;
      for (int j = 0; j < (int)primes.size(); j++) if (msk>>j&1) {
        mul *= primes[j];
      }
      (dp[mul] += res) %= mod;
    }
    last = res;
  }
  cout << last << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
