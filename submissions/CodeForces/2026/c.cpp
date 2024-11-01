#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll res = 0;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (s[i]-'0') v.push_back(i+1);
  }
  for (int i = n-1; ~i; --i) {
    if (s[i] == '0') {
      res += i+1;
      if (v.size() and v.back() > i) v.pop_back();
    }
  }
  for (int i = 0; i < ((int)v.size()+1)/2; i++) {
    res += v[i];
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
