#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<ll>> pref(3, vector<ll>(n+1));
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    pref[0][i+1] = pref[0][i] + x;
    pref[1][i+1] = pref[1][i] + (i+1) * x;
    pref[2][i+1] = pref[2][i] + (n-i) * x;
  }
  auto cost_point = [&](int l, int r, int m) {
    ll res = (pref[1][r+1] - pref[1][m+1]) - (m+1)*(pref[0][r+1]-pref[0][m+1])
           + (pref[2][m] - pref[2][l]) - (n-m) * (pref[0][m]-pref[0][l]);
    return res;
  };
  vector<vector<ll>> cost(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int l = i, r = j;
      while (l < r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (cost_point(i, j, m1) <= cost_point(i, j, m2)) r = m2 - 1;
        else l = m1 + 1;
      }
      cost[i][j] = cost_point(i, j, r);
    }
  }
  vector<ll> dp(n, 1e18), next_dp(n);
  auto calc = [&](auto &&self, int l, int r, int x, int y) -> void {
    if (l > r) return;
    auto m = midpoint(l, r);
    pair<ll, int> best = {LLONG_MAX, -1};
    for (int i = x; i <= min(y, m); i++)
      best = min(best, {(i ? dp[i-1] : 0) + cost[i][m], i});
    next_dp[m] = best.first;
    self(self, l, m-1, x, best.second);
    self(self, m+1, r, best.second, y);
  };
  for (int i = 0; i < k; i++) {
    calc(calc, 0, n-1, 0, n-1);
    swap(dp, next_dp);
  }
  cout << dp.back() << '\n';
}

// uma vez definido uma função de custo C(l, r) que calcula
// o menor custo pra juntar as casas de [l, r] em uma escola,
// basta fazer uma dp divide and conquer
//
// dado que a melhor posição pra colocar a escola que junta [l, r]
// é x, então o custo pra colocar ela lá é
// for (int i = l; i <= r; i++) cost += abs(i-x) * c[i]
//
// definindo somas prefixas (1-indexadas)
// - p[0][i+1]: p[0][i] + c[i]
// - p[1][i+1]: p[0][i] + i * c[i]
// - p[2][i+1]: p[0][i] + (n-i+1) * c[i]
//
// então C(l, r) = (p[1][r+1] - p[1][x+1]) - (l+1)*(p[0][r+1]-p[0][x+1])
//               + (p[2][x] - p[2][l]) - (n-x) * (p[0][x]-p[0][l]);
//
// mas como encontrar o melhor ponto pra um intervalo [l, r] ???
//
// da pra achar com busca ternária mas parece errado
//
// TODO: entender como passa sem a gambiarra da busca ternária

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
