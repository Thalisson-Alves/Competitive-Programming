#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<array<int, 2>> g(n);
  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v >> f[i];
    if (u > v) swap(u, v);
    g[i] = {--u, --v};
  }
  constexpr ll mod = 1e9+7;
  using T = array<array<ll, 2>, 2>;
  auto dfs = [&](auto &&self, int u) -> T {
    if (u == -1) return {{{1, 0},{0, 1}}};
    auto l = self(self, g[u][0]);
    auto r = self(self, g[u][1]);
    T res = {{{0,0}, {0,0}}};
    bool it[] = {0, 1};
    for (auto ci : it) {
      for (auto ri : it) {
        for (auto cj : it) {
          for (auto rj : it) {
            (res[!(ci&&cj)][~f[u]?f[u]:!(ri&&rj)] += l[ci][ri] * r[cj][rj] % mod) %= mod;
          }
        }
      }
    }
    return res;
  };
  auto res = dfs(dfs, 0);
  cout << (res[0][1]+res[1][0])%mod << '\n';
}

// da pra calcular a quantidade de jeitos de dar 0 ou 1
// levando em consideração o valor dos travados (cnt) e
// considerando que nenhum tivesse travado (should)
// a resposta seria should[0]-cnt[0] se should[0] > cnt[0]
// ou should[1]-cnt[1] caso contrário
//
// o problema dessa abordagem é que não da pra saber qual
// valor (should ou cnt) é maior por causa dos mods
//
// outra ideia é calcular dp[i][j] onde dp[i][j] é a quantidade
// de jeitos de dar j quando era pra dar i, daí a resposta seria
// dp[0][1]+dp[1][0] da raiz

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
