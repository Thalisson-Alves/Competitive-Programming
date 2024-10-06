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
  vector<ll> pref(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> pref[i];
    pref[i] += pref[i-1];
  }
  vector<ll> dp(n+1, 1e18), next_dp(n+1);
  dp[0] = 0;
  auto calc = [&](auto &&self, int l, int r, int x, int y) -> void {
    if (l > r) return;
    int m = midpoint(l, r);
    pair<ll, int> best = {LLONG_MAX, -1};
    for (int i = x; i < min(y+1, m); i++)
      best = min(best, {dp[i] + (pref[m]-pref[i])*(pref[m]-pref[i]), i});
    next_dp[m] = best.first;
    self(self, l, m-1, x, best.second);
    self(self, m+1, r, best.second, y);
  };
  for (int i = 0; i < k; i++) {
    calc(calc, 1, n, 0, n-1);
    swap(dp, next_dp);
  }
  cout << dp[n] << '\n';
}

// encontrar o menor custo total em dividir o array inicial
// em k subarrays onde o custo de cada subarray é igual a
// sua soma ao quadrado
//
// dp[i][j] é o menor custo para dividir em j subarrays
// considerando os i primeiros elementos
//
// a transição dessa dp seria:
// for (int l = 0; l < i; l++) if (dp[l][j-1] != LLONG_MAX) {
//   dp[i][j] = min(dp[i][j], dp[l][j-1] + (pref[i]-pref[l])*(pref[i]-pref[l]));
// }
//
// mas essa transição é muito lenta, então bora melhorar isso ae
//
// Ideia 1 (deu errado):
//
// (pref[i]-pref[l])^2 = pref[i]^2 - 2*pref[i]*pref[l] + pref[l]^2
//
// se eu já processei o indice l, então dp[l][j-1] e pref[l] são constantes
// a única variável é o pref[i], pq depende de quando vai valer a pena
// eu usar esse valor, então da pra guardar retas onde x é pref[i]
//
// se formos escrever a reta como y = a*x + b, temos:
//
// a = -2*pref[l]
// b = pref[l]^2 + dp[l][j-1]
//
// daí pra um dado i, basta encontrar a reta com menor y no x igual a pref[i]
// dessa forma dp[i][j] é igual a F(pref[i]) + pref[i]^2
//
// ou seja, só guardar k lichao que da pra fazer a transição em O(log)
//
// deu TLE :(
//
// Ideia 2:
//
// a solução mesmo gira em torno do fato de que existe uma posição ótima
// (vou chamar ela de opt) tal que dp[i][j] = dp[opt][j-1] + (pref[i]-pref[opt])^2
// é mínimo, e que pra todo indice l >= i o ponto ótimo de l vai ser no mínimo opt
// isso acontece por causa de um negócio chamado "Quadrangle Inequality"
//
// daí da pra meter um algoritmo de dividir e conquistar pra resolver em O(k*log(n))

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
