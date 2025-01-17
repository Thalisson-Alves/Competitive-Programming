#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MAX_N = 1e6;
vector<char> is_prime(MAX_N+1, true);
vector<ll> primes;
void sieve() {
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= MAX_N; i++) {
    if (not is_prime[i]) continue;
    primes.push_back(i);
    for (ll j = i * i; j <= MAX_N; j+=i)
      is_prime[j] = false;
  }
}

void solve() {
  sieve();
  ll n;
  cin >> n;
  ll res = 0;
  for (int i = 0; i < (int)primes.size(); i++) {
    if (primes[i]*primes[i] > n / primes[i] / primes[i]) break;
    ll cur = 1;
    for (int j = 0; j < 8; j++) {
      if (cur > n / primes[i]) {
        cur = n+1;
        break;
      }
      cur *= primes[i];
    }
    res += (cur <= n);
    for (int j = i+1; j < (int)primes.size(); j++) {
      auto x = primes[i]*primes[j];
      if (x <= n / x) res++;
    }
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
