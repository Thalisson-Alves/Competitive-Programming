#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> w(n);
  for (auto &x : w) cin >> x;
  vector<ll> cost(1<<n);
  for (int i = 1; i < 1<<n; i++) {
    for (int j = 0; j < n; j++) if (i>>j&1) {
      cost[i] += w[j];
    }
  }
  vector<pair<int, int>> dp(1<<n, {n, m});
  dp[0] = {1, 0};
  for (int i = 0; i < 1<<n; i++) {
    for (int j = 0; j < n; j++) if (i>>j&1) {
      auto [rides, weight] = dp[i^(1<<j)];
      if (weight+w[j] <= m) dp[i] = min(dp[i], {rides, weight+w[j]});
      else dp[i] = min(dp[i], {rides+1, w[j]});
    }
  }
  cout << dp.back().first << '\n';
}

// quantidade minima de elevadores pra levar n <= 20 pessoas
// considerando que o elevador suporta no máximo X de peso
// e cada pessoa pesa w[i]
//
// pra cada mascara da pra guardar quantos elevadores são necessários
// e qual o peso do último elevador
//
// daí pra cada máscara tento colocar a pessoa `i` no último elevador
// ou crio um novo caso ele já esteja cheio

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
