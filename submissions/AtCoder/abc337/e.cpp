#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve() {
  int n;
  cin >> n;

  int m = 32 - __builtin_clz(n-1);
  cout << m << endl;

  vector<bitset<100>> bs(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i & (1 << j))
        bs[j].set(i);
    }
  }

  for (int i = 0; i < m; i++) {
    cout << bs[i].count();
    for (int j = 0; j < n; j++) {
      if (bs[i][j]) cout << ' ' << j+1;
    }
    cout << endl;
  }

  string s;
  cin >> s;

  auto mask = bs[0];
  for (int i = 0; i < n; i++) mask.set(i);
  for (int i = 0; i < m; i++) {
    mask &= (s[i] == '1' ? bs[i] : ~bs[i]);
  }

  int res = 0;
  for (int i = 0; !res and i < n; i++)
    if (mask[i])
      res = i + 1;

  cout << res << endl;
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
