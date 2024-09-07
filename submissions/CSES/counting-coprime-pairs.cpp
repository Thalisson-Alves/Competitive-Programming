#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n; cin >> n;
  constexpr int MAXN = 1e6;
  vector<int> hist(MAXN+1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    hist[x]++;
  }
  ll res = (ll)n*(n-1)/2;
  vector<int> lp(MAXN+1), mob(MAXN+1);
  lp[1] = mob[1] = 1;
  for (int i = 2; i <= MAXN; i++) {
    if (!lp[i]) {
      for (int j = i; j <= MAXN; j+=i)
        if (!lp[j]) lp[j] = i;
    }
    if (lp[i/lp[i]] == lp[i]) mob[i] = 0;
    else mob[i] = -1 * mob[i / lp[i]];
    int cnt = 0;
    for (int j = i; j <= MAXN; j+=i) cnt += hist[j];
    res += mob[i] * cnt * (cnt - 1ll) / 2;
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
