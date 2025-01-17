#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  char a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  for (auto c : s) {
    if (c != a) c = b;
    cout << c;
  }
  cout << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
