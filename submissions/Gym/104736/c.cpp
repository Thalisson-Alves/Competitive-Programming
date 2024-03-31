#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

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
  int n, k;
  cin >> n >> k;
  if (k > n) {
    cout << "0\n";
    return;
  }
  constexpr int mod = 1e9 + 7, p1 = 1e5 + 3;

  ll h1 = 0;
  map<ll, int> dp; dp[h1] = -1;
  vector<int> hist(k);
  unordered_map<int, int> st; st[0] = k;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    h1 += fpow(p1, x, mod);
    st[hist[x-1]]--;
    st[++hist[x-1]]++;
    if (!st[0]) {
      for (int j = 0; j < k; j++) {
        st[hist[j]]--;
        st[--hist[j]]++;
        h1 -= fpow(p1, j+1, mod);
      }
    }

    auto it = dp.find(h1);
    if (it == dp.end()) {
      dp[h1] = i;
    } else {
      res = max(res, (i - it->second));
    }
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
