#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n; cin >> n;
  vector<int> res{1};
  int total = 1;
  while (total + 2ll*res.back() <= n) {
    res.push_back(2 * res.back());
    total += res.back();
  }
  if (total != n) res.push_back(n - total);
  sort(begin(res), end(res));
  cout << size(res)-1 << '\n';
  for (int i = 1; i < (int)size(res); i++)
    cout << res[i]-res[i-1] << " \n"[i == (int)size(res)-1];
}

// menor sequencia não decrescente que somada dá n
// essa sequencia tem que começar em 1
// e o próximo elemento da sequencia tem que ser
// no máximo o dobro do anterior
//
// n = 9
// res = 1 + 2 + 2 + 4
//
// acho que da pra só ir dobrando o valor sempre
// até passar de n, daí pega o que sobrar e "reordena"
// a sequencia pra ficar não decrescente

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
