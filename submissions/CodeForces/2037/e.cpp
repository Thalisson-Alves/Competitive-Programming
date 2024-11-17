#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  constexpr auto ask = [](int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int x; cin >> x;
    return x;
  };
  string res(n, '?');
  for (int l = n-1, r = n, prev = 0, ones = 0; l; --l) {
    auto x = ask(l, r);
    if (x == prev) {
      if (ones) res[l-1] = '1', ones++;
      continue;
    }
    res[l-1] = '0';
    prev += ones;
    int dif = x-prev;
    for (int i = l; dif and i < n; i++) {
      if (res[i] == '?') res[i] = '1', --dif, ones++;
    }
    prev = x;
    if (dif) return void(cout << "! IMPOSSIBLE" << endl);
  }
  for (int i = n-1; i and res[i] == '?'; --i) res[i] = '0';
  if (res.find('?') != string::npos) return void(cout << "! IMPOSSIBLE" << endl);
  cout << "! " << res << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  while (t--) solve();
}
