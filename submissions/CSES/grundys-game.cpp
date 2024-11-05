#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  static vector<int> dp(2000);
  if (dp.size() < int(1e6)) {
    for (int i = 3; i < (int)dp.size(); i++) {
      set<int> st;
      for (int j = 1; j < i; j++) {
        if (j!=i-j) st.insert(dp[j]^dp[i-j]);
      }
      for (auto x : st)
        if (x == dp[i]) dp[i]++;
        else break;
    }
    dp.resize(1e6+1, 1);
  }
  int n; cin >> n;
  cout << (dp[n] ? "first" : "second") << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  while (t--) solve();
}
