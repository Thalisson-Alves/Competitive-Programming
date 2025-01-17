#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, d;
  cin >> n >> d;
  string s;
  cin >> s;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (s[i] == '@')
      v.push_back(i);
  }
  string res(n, '.');
  for (int i = 0; i < (int)v.size()-d; i++) {
    res[v[i]] = '@';
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
