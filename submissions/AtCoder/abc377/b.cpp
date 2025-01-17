#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  set<int> row, col;
  for (int i = 0; i < 8; i++) row.insert(i), col.insert(i);
  for (int i = 0; i < 8; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 8; j++) {
      if (s[j] == '#') col.erase(j), row.erase(i);
    }
  }
  cout << row.size() * col.size() << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
