#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> pref(n+1);
  for (int i = 0; i < n; i++) pref[i+1] = pref[i] + s[i]-'0';
  ll res = 0;
  map<int, int> cnt;
  for (int i = 0; i <= n; i++) {
    res += cnt[pref[i]-i];
    cnt[pref[i]-i]++;
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  while (t--) solve();
}
