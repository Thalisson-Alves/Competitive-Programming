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

ll cnt_divisors(int x, const vector<int> &max_prime) {
  ll res = 1;
  prime_factor_iter(x, max_prime, [&res](int, int cnt) {
    res *= cnt + 1;
  });
  return res;
}

ll sum_divisors(int x, const vector<int> &max_prime) {
  ll res = 1;
  prime_factor_iter(x, max_prime, [&res](int p, int cnt) {
    // sum(p**i for i in range(cnt+1))
    res *= (fpow(p, cnt + 1) - 1) / (p - 1);
  });
  return res;
}
