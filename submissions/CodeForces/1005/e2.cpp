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
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  auto f = [&](int k) {
    ll res = 0, add = 0;
    int sum = 0;
    map<int, int> mp;
    mp[0] = 1;
    for (auto x : a) {
      if (x < k) add -= mp[--sum];
      else add += mp[sum++];
      res += add;
      ++mp[sum];
    }
    return res;
  };

  cout << f(m) - f(m+1) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

/* f(x) é o número de subarrays com mediana maior ou igual a x
 * então a resposta é f(m) - f(m+1)
 *
 * sendo: pref[i] = pref[i-1] + (a[i] >= m ? 1 : -1)
 *
 * a mediana de a[l..r] é maior ou igual a m se pref[r] > pref[l]
 * então, pra cada soma prefixa basta contar quantas somas menores
 * já foram vistas
 *
 * da pra usar uma segtree pra isso (ou usar a mágica acima)
 *
 * soma `n` nos valores pra eliminar indices negativos, ficaria:
 *
 * seg.set(n, 1);
 * int pref = 0;
 * for (auto x : a) {
 *   pref += (x >= m ? 1 : -1);
 *   res += seg.query(0, pref + n - 1);
 *   seg.update(pref + n, 1);
 * }
 */
