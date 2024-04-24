#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int a, b, w;
  cin >> a >> b >> w;
  w *= 1000;
  auto l = (w + b - 1) / b, r = w / a;
  if (l > r) cout << "UNSATISFIABLE\n";
  else cout << l << ' ' << r << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
