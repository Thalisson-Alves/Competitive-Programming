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
  int cx, cy;
  cin >> cx >> cy;
  --cx, --cy;
  vector<string> g(n);
  for (auto &x : g) cin >> x;
  string s; cin >> s;
  for (auto c : s) {
    if (c == 'U' and cx and g[cx-1][cy] == '.')
      --cx;
    else if (c == 'L' and cy and g[cx][cy-1] == '.')
      --cy;
    if (c == 'D' and cx+1<n and g[cx+1][cy] == '.')
      ++cx;
    else if (c == 'R' and cy+1<m and g[cx][cy+1] == '.')
      ++cy;
  }
  cout << cx+1 << ' ' << cy+1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
