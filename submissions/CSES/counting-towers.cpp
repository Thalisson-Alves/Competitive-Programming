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
  constexpr ll mod = 1e9+7;
  array<ll, 2> dp{1,1};
  for (int i = 1; i < n; i++) dp = {(dp[0]*4+dp[1])%mod, (dp[0]+dp[1]*2)%mod};
  cout << (dp[0]+dp[1])%mod << '\n';
}

// quantidade de jeitos diferentes de
// preencher um retangulo 2 x N
//
// dp[i][0] = altura i com os blocos separados
// dp[i][1] = altura i com os blocos juntos

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
