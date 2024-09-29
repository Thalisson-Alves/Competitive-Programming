#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m+1);
  for (int i = 0; i < n; i++) {
    int w, v;
    cin >> w >> v;
    a[w].push_back(v);
  }
  vector<ll> dp(m+1, LLONG_MIN);
  dp[0] = 0;
  for (int i = 1; i <= m; i++) {
    if (empty(a[i])) continue;
    vector<ll> f{0};
    priority_queue<ll> pq;
    for (auto v : a[i]) pq.push(v-1);
    for (int k = 1; i*k <= m; k++) {
      auto d = pq.top();
      pq.pop();
      f.push_back(f.back()+d);
      pq.push(d-2);
    }
    for (int j = m; ~j; --j) {
      for (int k = 1; j+i*k <= m; k++) {
        if (dp[j] != LLONG_MIN)
          dp[j+k*i] = max(dp[j+k*i], dp[j]+f[k]);
      }
    }
  }
  cout << *max_element(begin(dp), end(dp)) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
