#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll n;
  cin >> n;
  auto dfs = [&](auto &&self, string a, string b) -> ll {
    if (a.size() and stoll(a + b) > n) return 0;
    ll res = !a.empty();
    for (int i = a.empty(); i < 10; i++) {
      res += self(self, a + char(i + '0'), b + char(i + '0'));
    }
    return res;
  };
  cout << dfs(dfs, "", "") << '\n';
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
