#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

vector<int> kmp(const string &p) {
  int m = (int)p.size(), t = -1;
  vector<int> bs(m + 1, -1);

  for (int i = 1; i <= m; i++) {
    for (; t > -1 and p[t] != p[i - 1]; t = bs[t]);
    ++t;
    bs[i] = (i == m or p[t] != p[i]) ? t : bs[t];
  }

  return bs;
}

ll fpow(ll x, ll p, ll mod) {
  ll res = 1;
  while (p) {
    if (p & 1) res = res * x % mod;
    p >>= 1;
    x = x * x % mod;
  }
  return res;
}

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  auto bs = kmp(s);
  constexpr ll mod = 1e9 + 7;
  vector<vector<ll>> memo(n+1, vector<ll>(size(s), -1));
  auto dp = [&](auto &&self, int i, int j) -> ll {
    if (j == (int)size(s)) return fpow(26, n-i, mod);
    if (i >= n) return 0;
    auto &res = memo[i][j];
    if (~res) return res;
    res = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
      if (c == s[j]) (res += self(self, i+1, j+1)) %= mod;
      else {
        int nj = j;
        while (nj >= 0 and s[nj] != c) nj = bs[nj];
        (res += self(self, i+1, nj+1)) %= mod;
      }
    }
    return res;
  };
  cout << dp(dp, 0, 0) << '\n';
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
