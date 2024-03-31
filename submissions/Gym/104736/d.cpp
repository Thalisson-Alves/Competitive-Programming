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
  vector<string> v(n);
  for (auto &x : v) cin >> x;
  auto query = [&](const string_view &g) {
    int res = 0;
    for (const auto &x : v) {
      bool valid = true;
      for (int i = 0; valid and i < 5; i++) {
        if (g[i] == 'X' and v[0].find(x[i]) != string::npos)
          valid = false;
        else if (g[i] == '!' and (v[0].find(x[i]) == string::npos or v[0][i] == x[i]))
          valid = false;
        else if (g[i] == '*' and x[i] != v[0][i])
          valid = false;
      }
      res += valid;
    }
    return res;
  };

  int q;
  cin >> q;
  while (q--) {
    string g;
    cin >> g;
    cout << query(g) << '\n';
  }
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
