#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  double mp[100][100][100];
  memset(mp, 0, sizeof(mp));
  auto dp = [&mp](auto &&self, int a, int b, int c) -> double {
    if (max({a, b, c}) >= 100) return 0;
    auto &res = mp[a][b][c];
    if (res) return res;

    int s = a + b + c;
    if (a) res += (self(self, a + 1, b, c) + 1) * a / s;
    if (b) res += (self(self, a, b + 1, c) + 1) * b / s;
    if (c) res += (self(self, a, b, c + 1) + 1) * c / s;
    return res;
  };

  int a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(7) << dp(dp, a, b, c) << '\n';
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
