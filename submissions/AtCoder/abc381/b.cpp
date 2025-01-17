#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  if (s.size() & 1) {
    cout << "No\n";
    return;
  }
  map<char, int> hist;
  for (int i = 0; i < (int)s.size()/2; i++) {
    if (s[2*i] != s[2*i+1]) {
      cout << "No\n";
      return;
    }
    hist[s[2*i]]++;
  }
  for (auto [x, y] : hist) {
    if (y > 1) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
