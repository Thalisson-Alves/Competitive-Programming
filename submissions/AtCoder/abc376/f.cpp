#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> dp(n, LLONG_MAX);
  dp[1] = 0;
  char pc = 'L'; int pt = 0;
  for (int i = 0; i < q; i++) {
    vector<ll> next_dp(n, LLONG_MAX);
    char c; int t;
    cin >> c >> t; --t;
    for (int oh = 0; oh < n; ++oh) if (dp[oh] != LLONG_MAX) {
      int l = pt, r = oh;
      if (pc == 'R') swap(l, r);
      int u = l, v = r;
      if (c == 'R') swap(u, v);
      if (t <= u) {
        if (v < t or v > u) {
          next_dp[v] = min(next_dp[v], dp[oh] + u-t);
          int next_v = (t+1)%n;
          next_dp[next_v] = min(next_dp[next_v], dp[oh] + n-u+t + t+1-v + (v>u?n:0));
        } else {
          next_dp[(v+(v==t))%n] = min(next_dp[(v+(v==t))%n], dp[oh] + n-u+t+(v==t));
          int next_v = (t-1+n)%n;
          next_dp[next_v] = min(next_dp[next_v], dp[oh] + u-t+v-t+1);
        }
      } else {
        if (v > t or v < u) {
          next_dp[v] = min(next_dp[v], dp[oh] + t-u);
          int next_v = (t-1+n)%n;
          next_dp[next_v] = min(next_dp[next_v], dp[oh] + u+n-t + v-t+1 + (v<u?n:0));
        } else {
          next_dp[(v-(v==t)+n)%n] = min(next_dp[(v-(v==t)+n)%n], dp[oh] + u+n-t+(v==t));
          int next_v = (t+1)%n;
          next_dp[next_v] = min(next_dp[next_v], dp[oh] + t-u+t-v+1);
        }
      }
    }
    pc = c, pt = t;
    swap(dp, next_dp);
  }
  cout << *min_element(begin(dp), end(dp)) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
