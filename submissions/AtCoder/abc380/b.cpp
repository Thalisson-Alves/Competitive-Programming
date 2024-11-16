#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int cur = 0;
  for (int i = 1; i < (int)s.size(); i++) {
    if (s[i] == '|') {
      cout << cur << " \n"[i == (int)s.size()-1];
      cur = 0;
    } else cur++;
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
