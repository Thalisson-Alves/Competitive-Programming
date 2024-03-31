#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  string s;
  ll n;
  cin >> s >> n;
  for (auto &x : s) x -= 'a';

  constexpr ll mod = 1e9 + 7;
  n %= mod;

  vector<int> hist(26);
  ll non_inv = 0, inv = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    for (int j = 0; j < (int)hist.size(); j++) {
      if (s[i] > j) (non_inv += hist[j]) %= mod;
      else if (s[i] < j) (inv += hist[j]) %= mod;
    }
    hist[s[i]]++;
  }

  cout << ((inv * n) % mod + ((non_inv + inv) * ((n * (n - 1) / 2) % mod))) % mod << '\n';
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
